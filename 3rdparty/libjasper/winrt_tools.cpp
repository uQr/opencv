#include <string>

#ifdef __cplusplus
    extern "C"
#endif
// returns WINRT-supported LocalFolder path to get writeable file location.
char* getInstallPath()
{
    wchar_t* path = const_cast<wchar_t*>(Windows::Storage::ApplicationData::Current->LocalFolder->Path->Data());
	char* charPath = (char*) malloc(_MAX_PATH * sizeof(char));
    wcstombs(charPath, path, _MAX_PATH);
    strcat(charPath, "\\");
    strcat(charPath, tempnam(NULL, NULL));
    return charPath;
}