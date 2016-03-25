#pragma once

template <typename T>
inline void SafeRelease(T& ptr)
{
	if (ptr != NULL)
	{
		ptr->Release();
		ptr = NULL;
	}
}