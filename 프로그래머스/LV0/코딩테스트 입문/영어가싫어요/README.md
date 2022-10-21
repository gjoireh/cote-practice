```c
// stdlib.h
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Narrow String to Number Conversions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
_Check_return_                    _ACRTIMP double    __cdecl atof   (_In_z_ char const* _String);
_Check_return_ _CRT_JIT_INTRINSIC _ACRTIMP int       __cdecl atoi   (_In_z_ char const* _String);
_Check_return_                    _ACRTIMP long      __cdecl atol   (_In_z_ char const* _String);
_Check_return_                    _ACRTIMP long long __cdecl atoll  (_In_z_ char const* _String);
_Check_return_                    _ACRTIMP __int64   __cdecl _atoi64(_In_z_ char const* _String);
.
.
.

// 숫자의 크기, 형태에 따라 맞는 ato들이 있음
```