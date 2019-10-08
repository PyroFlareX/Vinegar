#include "VRUtils.h"

#include <iostream>

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

		void printTransformOfDevice(uint32_t deviceIndex)
		{
			if (deviceIndex >= ::vr::k_unMaxTrackedDeviceCount)
			{
				std::cout << "Index not in range\n";
				return;
			}
			glm::mat4 deviceMatrix = convertToMat4(TrackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			Transform device;
			
			device.pos = vec3(deviceMatrix[0][3], deviceMatrix[1][3], deviceMatrix[2][3]);
		}
	}
}