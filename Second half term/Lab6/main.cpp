#include<iostream>
#include<stdio.h>
#include <windows.h>
#include"run.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	system("E:\\代码\\大一下\\第六次实验\\Lab4.exe 5 Lab4.txt");
	char file[100] = "Lab4.txt";
	run(5, file);
	return 0;
}
