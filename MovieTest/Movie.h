#ifndef MOVIE_H_
#define MOVIE_H_

#include <dshow.h>

#include <tchar.h>

// このライブラリを追加しないとリンクエラーが出る
#pragma comment( lib, "strmiids.lib" )

class Movie
{
public:
	Movie(HRESULT& res) :m_rRes(res){}
	~Movie();

	/// <summary>
	/// グラフビルダーとメディアの取得
	/// </summary>
	HRESULT Initialize();
	
	/// <summary>
	/// 再生するムービーの作成
	/// </summary>
	/// <param name="pFileName">再生したいファイルの名前</param>
	void CreateMovie(const WCHAR* pFileName);

	/// <summary>
	/// 動画の再生 
	/// </summary>
	void Play();

	/// <summary>
	/// 動画の停止
	/// </summary>
	void Stop();

private:
	//デフォルトコンストラクタを削除
	Movie() = delete;

	HRESULT& m_rRes;

	IGraphBuilder* pGraphBuilder = nullptr;
	IMediaControl* pMediaControl = nullptr;
};

#endif // !MOVIE_H_
