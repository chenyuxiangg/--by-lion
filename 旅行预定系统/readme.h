#pragma once
/*
说明：
1、该系统仅支持英文名及数字以及ASCII码表中的符号
2、该版本中有一个未解决的问题：struct BESTRUCT 结构体的成员identy究竟是否需要用构造函数初始化
3、程序中的界面模块说明：module[0]:登录界面 module[1]:主界面 module[2]:信息录入界面 module[3]:信息查询界面，module[4]:各个查询
*/

/*
经验与总结：
1、创建窗口时，窗口过程函数的参数是先WPARAM,而后才是LPARAM
2、准备往宽字符数组里放东西时，应先将其初始化
3、点击按钮产生的消息会被父窗口的WM_COMMEND接收，并将该消息标志放在WPARAM参数里
*/