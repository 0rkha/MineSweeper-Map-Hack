#include <windows.h>
#include <stdio.h>
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = FindWindow(NULL, "Áö·Ú Ã£±â");
		if (hWnd != NULL) {
			BYTE buf[5000];
			DWORD dwProcessId = 0;
			DWORD dwThreadId = 0;
			dwThreadId = GetWindowThreadProcessId(hWnd, &dwProcessId);
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
			const LPVOID now = (LPVOID)0x01005360;
			int i, j, w, h;
			BYTE map[24][30];
			for(i=0; i<24; i++){
				ReadProcessMemory(hProcess, now+i*32, &buf, 33, NULL);
				if(buf[0]==16&&buf[1]==16) break;
				for(j=1; buf[j]!=16; j++){
					map[i][j-1]=buf[j];
					w=j;
				}
			}
			h=i;
			for(i = 0; i<h; i++){
				for(j=0; j<w; j++){
					switch(map[i][j]){
						case 143:
							printf("¡Ú");
							break;
						case 15:
							printf("¡Û");
							break;
					}
				}
				printf("\n");
			}
		}
}
