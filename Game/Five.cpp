#include "Five.h"
#include <windowsx.h>

// Recalculate drawing layout when the size of the window changes
//ok
void MainWindow::CalculateLayout()
{
	if (pRenderTarget != NULL)
	{
		D2D1_SIZE_F size = pRenderTarget->GetSize();
		m_CentreX = size.width / 2;
		m_CentreY = size.height / 2;
		m_GridLen = min(size.width, size.height) / 16;//网格高度
		m_topX = size.width / 2 - 7 * m_GridLen;//棋盘与窗口边缘的x距离
		m_topY = size.height / 2 - 7 * m_GridLen;//棋盘与窗口边缘的y距离
	}
}
//ok
HRESULT MainWindow::CreateGraphicsResources()
{
	HRESULT hr = S_OK;
	if (pRenderTarget == NULL)
	{

		//创建渲染器
		RECT rc;
		GetClientRect(m_hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

		hr = pFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(m_hwnd, size),
			&pRenderTarget);

		if (SUCCEEDED(hr))
		{
			hr = pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &pBrush);//这句有什么用？只是用于创建一个背景画刷，实质并不影响什么
			if (SUCCEEDED(hr))
			{
				CalculateLayout();
			}
		}
	}
	return hr;
}
//ok
void MainWindow::CreateFiveChessGrid()
{
	//set background color
	pRenderTarget->Clear(D2D1::ColorF(0.96f, 0.79f, 0.39f, 1.0f));//将渲染区域以指定颜色覆盖
	pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::Black));
	float left = m_topX;
	float top = m_topY;
	float bottom = m_CentreY + 7 * m_GridLen;
	float right = m_CentreX + 7 * m_GridLen;
	//draw vert lines
	for (float i = 0; i < 14 * m_GridLen + 1; i += m_GridLen)
	{
		pRenderTarget->DrawLine(D2D1::Point2F(left + i, top), D2D1::Point2F(left + i, bottom), pBrush);//用指定画刷在指定点之间绘制直线
	}
	//draw horiz lines
	for (float i = 0; i < 14 * m_GridLen + 1; i += m_GridLen)
	{
		pRenderTarget->DrawLine(D2D1::Point2F(left, top + i), D2D1::Point2F(right, top + i), pBrush);
	}
	//draw special points
	pRenderTarget->FillEllipse(D2D1::Ellipse(
		D2D1::Point2F(m_CentreX, m_CentreY), m_GridLen / 6, m_GridLen / 6), pBrush);//Ellipse填充一个结构体，第一个参数是椭圆中心，第二、三个参数是x轴半径和y轴半径
	pRenderTarget->FillEllipse(D2D1::Ellipse(
		D2D1::Point2F(m_CentreX - 4 * m_GridLen, m_CentreY - 4 * m_GridLen), m_GridLen / 6, m_GridLen / 6), pBrush);
	pRenderTarget->FillEllipse(D2D1::Ellipse(
		D2D1::Point2F(m_CentreX + 4 * m_GridLen, m_CentreY + 4 * m_GridLen), m_GridLen / 6, m_GridLen / 6), pBrush);
	pRenderTarget->FillEllipse(D2D1::Ellipse(
		D2D1::Point2F(m_CentreX + 4 * m_GridLen, m_CentreY - 4 * m_GridLen), m_GridLen / 6, m_GridLen / 6), pBrush);
	pRenderTarget->FillEllipse(D2D1::Ellipse(
		D2D1::Point2F(m_CentreX - 4 * m_GridLen, m_CentreY + 4 * m_GridLen), m_GridLen / 6, m_GridLen / 6), pBrush);
}
//ok
void MainWindow::RenderChess()
{
	float left = m_CentreX - 7 * m_GridLen;
	float top = m_CentreY - 7 * m_GridLen;
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			if (m_chess[i][j] == 0)
			{
				continue;
			}
			if (m_chess[i][j] == 1)
			{
				pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::Black));
			}
			else
			{
				pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::White));
			}
			pRenderTarget->FillEllipse(D2D1::Ellipse(
				D2D1::Point2F(left + i*m_GridLen, top + j*m_GridLen), m_GridLen * 3 / 7, m_GridLen * 3 / 7), pBrush);
		}
	}
}
//ok
void MainWindow::OnPaint()
{
	HRESULT hr = CreateGraphicsResources();
	if (SUCCEEDED(hr))
	{
		PAINTSTRUCT ps;
		BeginPaint(m_hwnd, &ps);
		pRenderTarget->BeginDraw();//开启绘制模式
		//draw chess grid
		CreateFiveChessGrid();
		RenderChess();
		hr = pRenderTarget->EndDraw();
		// re-create the render target and all device-dependent resources
		if (hr == D2DERR_RECREATE_TARGET)
		{
			CreateGraphicsResources();
		}
		EndPaint(m_hwnd, &ps);
	}
}
//ok
void MainWindow::Resize()
{
	if (pRenderTarget != NULL)
	{
		RECT rc;
		GetClientRect(m_hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);
		pRenderTarget->Resize(size);
		CalculateLayout();
		InvalidateRect(m_hwnd, NULL, FALSE);//更新窗口，发出WM_PAINT消息
	}
}
//ok,have a question
BOOL MainWindow::OnLeftButtonDown(LPARAM lParam)
{
	float xPosition = LOWORD(lParam);//鼠标x坐标
	float yPosition = HIWORD(lParam);//鼠标y坐标
	//判断鼠标点击区域
	int x = (int)((xPosition - m_topX) / m_GridLen + 0.5);//如果移动窗口，m_topX与m_topY会改变么？不会，只有改变大小的时候才会改变
	int y = (int)((yPosition - m_topY) / m_GridLen + 0.5);

	if (x < 0 || x>14 || y < 0 || y>14)
	{
		return FALSE;
	}
	if (HasChess(x, y))
	{
		return FALSE;
	}
	if (m_IsBlack)//什么意思
	{
		m_chess[x][y] = 1;
		m_IsBlack = FALSE;
	}
	else
	{
		m_chess[x][y] = 2;
		m_IsBlack = TRUE;
	}
	m_xPosition = x;
	m_yPosition = y;
	return TRUE;

}
//ok
void MainWindow::OnLeftButtonUp()
{
	if (IsGameOver())
	{
		MessageBox(m_hwnd, TEXT("游戏结束"), TEXT("Five Chess"), MB_OK);
		ReInitialization();
	}
}
//ok
BOOL MainWindow::HasChess(int xPosition, int yPosition)
{
	if (m_chess[xPosition][yPosition] != 0)
	{
		return TRUE;
	}
	return FALSE;
}
//待看
BOOL MainWindow::IsGameOver()
{
	//horiz check
	int count = -1;
	for (int x = m_xPosition; x >= 0; --x)
	{
		if (m_chess[x][m_yPosition] == m_chess[m_xPosition][m_yPosition])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	for (int x = m_xPosition; x < 15; ++x)
	{
		if (m_chess[x][m_yPosition] == m_chess[m_xPosition][m_yPosition])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count >= 5)
	{
		return TRUE;
	}
	//vert check
	count = -1;
	for (int y = m_yPosition; y >= 0; --y)
	{
		if (m_chess[m_xPosition][y] == m_chess[m_xPosition][m_yPosition])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	for (int y = m_yPosition; y < 15; ++y)
	{
		if (m_chess[m_xPosition][y] == m_chess[m_xPosition][m_yPosition])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count >= 5)
	{
		return TRUE;
	}
	//clockwise check
	count = -1;
	for (int x = m_xPosition, y = m_yPosition; x > 0, y > 0; --x, --y)
	{
		if (m_chess[x][y] == m_chess[m_xPosition][m_yPosition])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	for (int x = m_xPosition, y = m_yPosition; x < 15, y < 15; ++x, ++y)
	{
		if (m_chess[x][y] == m_chess[m_xPosition][m_yPosition])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count >= 5)
	{
		return TRUE;
	}
	//anticlockwise check
	count = -1;
	for (int x = m_xPosition, y = m_yPosition; x > 0, y < 15; --x, ++y)
	{
		if (m_chess[x][y] == m_chess[m_xPosition][m_yPosition])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	for (int x = m_xPosition, y = m_yPosition; x < 15, y > 0; ++x, --y)
	{
		if (m_chess[x][y] == m_chess[m_xPosition][m_yPosition])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count >= 5)
	{
		return TRUE;
	}
	return FALSE;
}
//ok,用于重新绘制
void MainWindow::ReInitialization()
{
	m_IsBlack = TRUE;
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			m_chess[i][j] = 0;
		}
	}
	InvalidateRect(m_hwnd, NULL, FALSE);
}
//ok
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
	MainWindow win;

	if (!win.Create(TEXT("Five Chess"), WS_OVERLAPPEDWINDOW, 0, CW_USEDEFAULT, CW_USEDEFAULT, 480, 500))
	{
		return 0;
	}
	ShowWindow(win.Window(), nCmdShow);

	// Run the message loop.
	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
//ok
LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		if (FAILED(D2D1CreateFactory(
			D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory)))
		{
			return -1;  // Fail CreateWindowEx.
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		OnPaint();
		return 0;

	case WM_SIZE:
		Resize();
		return 0;

	case WM_LBUTTONDOWN:
		if (OnLeftButtonDown(lParam))
		{
			InvalidateRect(m_hwnd, NULL, FALSE);
		}
		return 0;

	case WM_LBUTTONUP:
		OnLeftButtonUp();
		return 0;

	case WM_SETCURSOR:
		SetCursor(LoadCursor(NULL, IDC_ARROW));
		return 0;

	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}

