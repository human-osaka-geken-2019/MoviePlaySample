#include <iostream>

#include <dshow.h>

#include "Movie.h"

int main()
{
	HRESULT hResult = NULL;

	hResult = CoInitialize(NULL);

	Movie movie(hResult);

	movie.Initialize();

	//マルチバイトしかダメ
	const WCHAR* fileName = L"Test.avi";
	movie.CreateMovie(fileName);

	movie.Play();

	while (true);

	return 0;
}
