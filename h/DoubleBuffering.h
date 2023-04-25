#pragma once
#include <Windows.h>

// double buffering
static int screenIndex; // �ܼ� ���� �ε���
static HANDLE screen[2]; // �ܼ� 2��

void ScreenInit(); // �ܼ� 2���� �غ��ϴ� �Լ�
void ScreenFlipping(); // ȭ�鿡 ������ �ܼ��� ����Ī �ϴ� �Լ�
void ScreenClear(); // ��ũ���� ��������� ����� �Լ�
void ScreenPrint(int x, int y, const char* string);
void ScreenRelease();