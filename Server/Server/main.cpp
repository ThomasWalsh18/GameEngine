#include <iostream>
#include <enet/enet.h>
#include <WinSock2.h>

static LRESULT CALLBACK CustomWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		HWND hwndCtl = (HWND)lParam;
		int code = HIWORD(wParam);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
struct Vector3 {
	float x;
	float y;
	float z;
};

void main()
{
	MSG msg = { 0 };
	HWND hWnd;
	int WIDTH = 500;
	int HEIGHT = 500;
	std::string title = "SERVER";
	Vector3 pos;
	bool press = false;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = -500.0f;

	HINSTANCE hInstance = 0;

	const char* Win32ClassName = "ServerWindow";

	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)CustomWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = DLGWINDOWEXTRA;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = NULL;//(HBRUSH)(COLOR_WINDOW);
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = Win32ClassName;
	wcex.hIconSm = 0;

	RegisterClassEx(&wcex);

	DWORD style = WS_CAPTION | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_SYSMENU;

	hWnd = CreateWindow(Win32ClassName, title.c_str(), style, 100, 100, WIDTH, HEIGHT, NULL, NULL, hInstance, NULL);


	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	
	if (enet_initialize() != 0)
	{
		std::cout << "Enet failed to initialise!" << std::endl;
	}

	ENetAddress address;
	ENetHost* server;
	ENetEvent enetEvent;

	ENetPacket* dataPacket;

	address.host = ENET_HOST_ANY;
	address.port = 1234;

	server = enet_host_create(&address, 32, 2, 0, 0);

	if (server == NULL)
	{
		std::cout << "Server failed to initialise!" << std::endl;
	}
	bool close = false;
	while (msg.message != WM_QUIT)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//do stuff here
		while (enet_host_service(server, &enetEvent, 0) > 0)
		{
			switch (enetEvent.type)
			{
			case ENET_EVENT_TYPE_CONNECT:

				std::cout << "A client connected from address " << enetEvent.peer->address.host << ":" << enetEvent.peer->address.port << "." << std::endl;

				enetEvent.peer->data = "This is a client";

				break;
			case ENET_EVENT_TYPE_DISCONNECT:
				std::cout << "The client from address " << enetEvent.peer->address.host << ":" << enetEvent.peer->address.port << " disconnected" << std::endl;

				enetEvent.peer->data = NULL;
				break;
			}
		}
		if (GetKeyState('W') & 0x0800 && press == false) {
			press = true;
		}
		if (press == true && GetKeyState('W') == 0) {
			press = false;
			pos.z -= 1;
		}
		dataPacket = enet_packet_create(&pos, sizeof(Vector3), ENET_PACKET_FLAG_RELIABLE);
		enet_host_broadcast(server, 0, dataPacket);

	}

	CloseWindow(hWnd);
	enet_host_destroy(server);
	atexit(enet_deinitialize);
}