#ifndef FFMFILTER_H
#define FFMFILTER_H

#include "ffmconfig.h"
#include <string>

class FfmTransform;
class FfmFilter : public CTransformFilter, public IFfmFilter
{
public:
	FfmFilter(LPUNKNOWN punk, HRESULT *phr);
	~FfmFilter();
	DECLARE_IUNKNOWN;

public:    
    static CUnknown * WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

public:
    STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, void ** ppv);

    HRESULT Transform(IMediaSample *pIn, IMediaSample *pOut);
    HRESULT CheckInputType(const CMediaType *mtIn);
    HRESULT CheckTransform(const CMediaType *mtIn, const CMediaType *mtOut);
    HRESULT DecideBufferSize(IMemAllocator *pAlloc,
                             ALLOCATOR_PROPERTIES *pProperties);
    HRESULT GetMediaType(int iPosition, CMediaType *pMediaType);

public:
	virtual int		setup(int media_type, char* ip, int port, char* app, char* stream);
	virtual void	setVideoSize(int width, int height);

private:
    CCritSec		m_EZrgb24Lock;
    CRefTime		m_effectStartTime;
    CRefTime		m_effectTime;

	FfmTransform*	m_pTranform;
};

#endif