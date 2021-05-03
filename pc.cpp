// checks the pc bit (32 and 64) and returns it, can be used for game hacks mainly.

BOOL IsPC64()
{
	BOOL b_is_wow64 = FALSE;

	typedef BOOL(WINAPI* LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fn_is_wow64_process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");

	if (NULL != fn_is_wow64_process)
	{
		if (!fn_is_wow64_process(GetCurrentProcess(), &b_is_wow64))
		{
			return FALSE;
		}
	}
	return b_is_wow64;
}
