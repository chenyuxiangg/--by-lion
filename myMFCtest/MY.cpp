#include "MY.h"

cmywinapp theapp;

BOOL cmywinapp::initinstance() {
	m_pmainwnd = new cmyframewnd;
	return TRUE;
}

cmyframewnd::cmyframewnd()
{
	mcreate();
}

void printallclasses() {
	CruntimeClass* pclass;
	for (pclass = CruntimeClass::pFirstClass; pclass != NULL; pclass = pclass->m_pNextClass)
	{
		cout << pclass->m_lpszClassname << endl;
		cout << pclass->m_nobjectSize << endl;
		cout << pclass->m_wSchema << endl;
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	cwinapp* app = afxgetapp();
	app->initapplication();
	app->initinstance();
	app->mrun();

	if (app->iskindof(CRUNTIME_CLASS(cview)))
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}

	//printallclasses();
	system("pause");
	return 0;
}