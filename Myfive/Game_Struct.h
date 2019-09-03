#pragma once
/*
*���ļ�����ͨ�õ����ݽṹ
*/
#ifndef GAME_STRUCT_H
#define GAME_STRUCT_H

//��������Ҫ��ͼƬ������GUIֱ����ͼ�����������ӣ��������ﲻ��Ҫʹ����ɫ
//ԭ���� class Mypoint
typedef struct STEP {
	int x;
	int y;
};

//���ӵ���ɫ
enum PIECE_COLOR { FNULL, BLACK, WHITE };

//�Ѷȼ���
enum DEGREE_DIFFICULT { FEASY, FDIFFICULT };

//�Ⱥ���
enum ORDER_PUT { ORDER_NONE,BEFORE, BEHAND };

//��Ϸģʽ
enum GAME_MODULE { MUDEL_NONE,PVP, PVM };

//�غ�
enum GAME_TURN { TURN_NONE,TURN_OF_OTHER, TURN_OF_YOU };

//��̨���̵�һ����,��������������Ҫ�ĵط�������
typedef struct BORD_POINT {
	PIECE_COLOR piece;
	char black_connect;
	char white_connect;
	bool weffect;
	bool beffect;

	BORD_POINT(int x = 0); //Ĭ�ϲ���xûʲô�ã���Ҫ��Ϊ���ܴﵽʹ��intֵ��ʼ��BORD_POINT
}BordPoint;

//��ǰλ�ü���������
enum CURRENT_CONNECT { NONE, WILL_2,O_CHONG_2,M_CHONG_2,O_ACTIVE_2,M_ACTIVE_2,O_CHONG_3,M_CHONG_3,O_AVTIVE_3,M_ACTIVE_3, WILL_5 };

//����
enum GAME_DIRECTION {
	DIRECT_UP = 1, DIRECT_LEFT, DIRECT_DOWN, DIRECT_RIGHT,
	DIRECT_LEFT_UP, DIRECT_RIGHT_UP, DIRECT_LEFT_DOWN, DIRECT_RIGHT_DOWN
};

//��������Ϊ
enum MACHINE_ACT { ACT_NULL, ACT_DEFENSE, ACT_ATTACK, ACT_BUILD };

#endif
