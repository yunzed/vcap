#ifndef VCAPENGINE_H
#define VCAPENGINE_H


#include "vcapconfig.h"

class VCapFilter;
class VCapCamera;
class VCapVideoEncode;
class VCapVMRRender;
class VCapEngine
{
public:
	VCapEngine();
	~VCapEngine();

public:
	void	start();
	void	stop();
	ICaptureGraphBuilder2*	getCaptureBuilder() { return m_pCaptureBuilder; }
	IGraphBuilder*	getGraphBuilder() { return m_pGraphBuilder; }
	IMediaControl*	getMediaControl() { return m_pMediaControl; }
	
private:
	void	init();

private:	
	ICaptureGraphBuilder2*	m_pCaptureBuilder;
	IGraphBuilder*	m_pGraphBuilder;	
	IMediaControl*	m_pMediaControl;
	bool	m_bStarted;
};

#endif