#include "ffmtransform.h"
#include "ffmoutformat.h"
#include "ffmaachandler.h"
#include "ffmh264handler.h"
#include "icodechandler.h"
#include "ffmlog.h"

FfmTransform::FfmTransform()
{	
	::av_register_all();
	avformat_network_init();
	
	m_pCodecHandler = NULL;
	m_nMediaType = 0;
}

FfmTransform::~FfmTransform()
{	
	if( m_pCodecHandler ) 
		delete m_pCodecHandler;
}

int	FfmTransform::setup(int media_type, char* ip, int port, char* app, char* stream) {
	m_nMediaType = media_type;
	if( media_type == FFM_MEDIA_AUDIO ) {
		m_pCodecHandler = new FfmAacHandler();
		m_pCodecHandler->setup(ip, port, app, stream);
	
	} else if( media_type == FFM_MEDIA_VIDEO) {
		m_pCodecHandler = new FfmH264Handler();
		m_pCodecHandler->setup(ip, port, app, stream);
	}

	return 0;
}

int		FfmTransform::onData(LONGLONG time,  char* src, int inlen, char* dest, int outlen) {
	if( m_pCodecHandler ) {
		return m_pCodecHandler->onData(time, src, inlen, dest, outlen);
	}

	return 0;
}

void	FfmTransform::close() {
	if( m_pCodecHandler ) {
		m_pCodecHandler->close();
	}
}

void	FfmTransform::setVideoSize(int width, int height)
{
	/*
	if( m_pH264Handler ) {
		m_pH264Handler->setVideoSize(width, height);
	}
	*/
}