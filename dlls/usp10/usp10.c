/*
 * Implementation of Uniscribe Script Processor (usp10.dll)
 *
 * Copyright 2005 Steven Edwards for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Notes:
 * Uniscribe allows for processing of complex scripts such as joining
 * and filtering characters and bi-directional text with custom line breaks.
 */

#include <stdarg.h>

#include "windef.h"
#include "winbase.h"
#include "winuser.h"
#include "usp10.h"

#include "wine/debug.h"

/**
 * some documentation here:
 *   http://www.microsoft.com/typography/developers/uniscribe/uniscribe.htm
 */

WINE_DEFAULT_DEBUG_CHANNEL(uniscribe);

BOOL WINAPI DllMain(HINSTANCE hInstDLL, DWORD fdwReason, LPVOID lpv)
{
    switch(fdwReason) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hInstDLL);
	    break;
	case DLL_PROCESS_DETACH:
	    break;
    }
    return TRUE;
}

HRESULT WINAPI ScriptGetProperties(const SCRIPT_PROPERTIES ***ppSp, int *piNumScripts)
{
    FIXME("%p,%p\n",ppSp,piNumScripts);
    return E_NOTIMPL;
}

HRESULT WINAPI ScriptGetFontProperties(HDC hdc, SCRIPT_CACHE *psc, SCRIPT_FONTPROPERTIES *sfp)
{
    FIXME("%p,%p,%p\n", hdc, psc, sfp);
    /* return something sensible? */
    if (NULL != sfp) {
        sfp->cBytes        = sizeof(SCRIPT_FONTPROPERTIES);
        sfp->wgBlank       = 0;
        sfp->wgDefault     = 0;
        sfp->wgInvalid     = 0;
        sfp->wgKashida     = 1;
        sfp->iKashidaWidth = 0;
    }
    return 0;
}

HRESULT WINAPI ScriptRecordDigitSubstitution(LCID Locale,SCRIPT_DIGITSUBSTITUTE *psds)
{
    FIXME("%ld,%p\n",Locale,psds);
    return E_NOTIMPL;
}

HRESULT WINAPI ScriptApplyDigitSubstitution(const SCRIPT_DIGITSUBSTITUTE* psds, 
                                            SCRIPT_CONTROL* psc, SCRIPT_STATE* pss)
{
    FIXME("%p,%p,%p\n",psds,psc,pss);
    return E_NOTIMPL;
}

HRESULT WINAPI ScriptItemize(const WCHAR *pwcInChars, int cInChars, int cMaxItems, 
                             const SCRIPT_CONTROL *psControl, const SCRIPT_STATE *psState, 
                             SCRIPT_ITEM *pItems, int *pcItems)
{
    FIXME("%s,%d,%d,%p,%p,%p,%p\n", debugstr_w(pwcInChars), cInChars, cMaxItems, 
          psControl, psState, pItems, pcItems);
    return E_INVALIDARG;
}

HRESULT WINAPI ScriptStringAnalyse(HDC hdc, 
				   const void *pString, 
				   int cString, 
				   int cGlyphs,
				   int iCharset,
				   DWORD dwFlags,
				   int iReqWidth,
				   SCRIPT_CONTROL *psControl,
				   SCRIPT_STATE *psState,
				   const int *piDx,
				   SCRIPT_TABDEF *pTabdef,
				   const BYTE *pbInClass,
				   SCRIPT_STRING_ANALYSIS *pssa)
{
  FIXME("(%p,%p,%d,%d,%d,0x%lx,%d,%p,%p,%p,%p,%p,%p): stub\n",
	hdc, pString, cString, cGlyphs, iCharset, dwFlags,
	iReqWidth, psControl, psState, piDx, pTabdef, pbInClass, pssa);
  if (1 > cString || NULL == pString) {
    return E_INVALIDARG;
  }
  if ((dwFlags & SSA_GLYPHS) && NULL == hdc) {
    return E_INVALIDARG;
  }

  return E_NOTIMPL;
}

HRESULT WINAPI ScriptStringFree(SCRIPT_STRING_ANALYSIS *pssa) {
  FIXME("(%p): stub\n",pssa);
  return S_OK;
}

HRESULT WINAPI ScriptIsComplex(const WCHAR* pwcInChars, int cInChars, DWORD dwFlags) {
  FIXME("(%s,%d,0x%lx): stub\n",  debugstr_w(pwcInChars), cInChars, dwFlags);
   return E_NOTIMPL;
}
