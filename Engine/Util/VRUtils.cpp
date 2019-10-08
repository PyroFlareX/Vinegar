#include "VRUtils.h"

namespace vn
{
	namespace vr
	{
		mat4 projMatrixL;
		mat4 projMatrixR;
		mat4 viewMatrixL;
		mat4 viewMatrixR;

		mat4 HMDMatrix;

		::vr::IVRSystem* m_pHMD;
		::vr::IVRCompositor* m_pCompositor;

		::vr::TrackedDevicePose_t TrackedDevicePose[::vr::k_unMaxTrackedDeviceCount];
		mat4 m_rmat4DevicePose[::vr::k_unMaxTrackedDeviceCount];
	}
}