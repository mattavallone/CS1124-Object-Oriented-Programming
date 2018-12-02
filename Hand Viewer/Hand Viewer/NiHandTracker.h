#ifndef NI_HAND_TRACKER_H__
#define NI_HAND_TRACKER_H__

#include "XnCppWrapper.h"
#include "XnCyclicStackT.h"
#include "XnHashT.h"

// Hand position history length (positions)
#define MAX_HAND_TRAIL_LENGTH	10

typedef XnCyclicStackT<XnPoint3D, MAX_HAND_TRAIL_LENGTH> Trail;
typedef XnHashT<XnUserID, Trail> TrailHistory;

class HandTracker
{
public:
	HandTracker(xn::Context& context);
	~HandTracker();

	XnStatus Init();
	XnStatus Run();

	const TrailHistory&	GetHistory()	const { return m_History; }

private:
	// OpenNI Gesture and Hands Generator callbacks
	static void XN_CALLBACK_TYPE Gesture_Recognized(xn::GestureGenerator&	generator,
		const XnChar*			strGesture,
		const XnPoint3D*		pIDPosition,
		const XnPoint3D*		pEndPosition,
		void*					pCookie);
	static void XN_CALLBACK_TYPE Gesture_Process(xn::GestureGenerator&	/*generator*/,
		const XnChar*			/*strGesture*/,
		const XnPoint3D*		/*pPosition*/,
		XnFloat					/*fProgress*/,
		void*					/*pCookie*/) {}
	static void XN_CALLBACK_TYPE Hand_Create(xn::HandsGenerator& generator,
		XnUserID			nId,
		const XnPoint3D*	pPosition,
		XnFloat				fTime,
		void*				pCookie);
	static void XN_CALLBACK_TYPE Hand_Update(xn::HandsGenerator& generator,
		XnUserID			nId,
		const XnPoint3D*	pPosition,
		XnFloat				fTime,
		void*				pCookie);
	static void XN_CALLBACK_TYPE Hand_Destroy(xn::HandsGenerator& generator,
		XnUserID			nId,
		XnFloat				fTime,
		void*				pCookie);

	xn::Context&			m_rContext;
	TrailHistory			m_History;
	xn::GestureGenerator	m_GestureGenerator;
	xn::HandsGenerator		m_HandsGenerator;

	static XnListT<HandTracker*>	sm_Instances;	// Living instances of the class

private:
	XN_DISABLE_COPY_AND_ASSIGN(HandTracker);
};

#endif //NI_HAND_TRACKER_H__