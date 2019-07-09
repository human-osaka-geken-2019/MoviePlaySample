#include "Movie.h"

Movie::~Movie()
{
	//解放処理
	if (pGraphBuilder != nullptr)
	{
		pGraphBuilder->Release();
	}

	if (pMediaControl != nullptr)
	{
		pMediaControl->Release();
	}

	//comの終了
	CoUninitialize();
}

HRESULT Movie::Initialize()
{
	//グラフィックビルダーの取得
	m_rRes = CoCreateInstance(
		CLSID_FilterGraph,
		NULL,
		CLSCTX_INPROC,
		IID_IGraphBuilder,
		(LPVOID *)&pGraphBuilder
	);

	//エラー処理
	if (FAILED(m_rRes))
	{
		printf("error");
		return m_rRes;
	}

	//メディアコントローラの取得
	m_rRes = pGraphBuilder->QueryInterface(
		IID_IMediaControl,
		(void**)&pMediaControl
	);

	//エラー処理
	if (FAILED(m_rRes)) 
	{ 
		printf("error");
		return m_rRes; 
	}

	return m_rRes;
}

void Movie::CreateMovie(const WCHAR* pFileName)
{
	pMediaControl->RenderFile((BSTR)pFileName);
}

void Movie::Play()
{
	pMediaControl->Run();
}

void Movie::Stop()
{
	pMediaControl->Stop();
}
