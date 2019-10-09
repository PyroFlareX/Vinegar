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

		bool initVR()
		{
			// Loading the SteamVR Runtime
			::vr::EVRInitError eError = ::vr::VRInitError_None;
			m_pHMD = ::vr::VR_Init(&eError, ::vr::VRApplication_Scene);
			bool result;


			if (eError == ::vr::VRInitError_None)
			{
				m_pCompositor = ::vr::VRCompositor();

				projMatrixL = getProjMatrix(::vr::Eye_Left);
				projMatrixR = getProjMatrix(::vr::Eye_Right);
				viewMatrixL = getViewMatrix(::vr::Eye_Left);
				viewMatrixR = getViewMatrix(::vr::Eye_Right);

				result = true;
			}
			return result;
		}

		void updateTracking()
		{
			//m_pHMD->GetDeviceToAbsoluteTrackingPose(::vr::ETrackingUniverseOrigin::TrackingUniverseStanding, 0.0f, TrackedDevicePose, ::vr::k_unMaxTrackedDeviceCount);
			// ^ Is old code, but is still relevant for future reference
			
			//Tells Compositor that Vinegar is in focus, and fills TrackedDevicePose[] with the mat Transforms of the tracked devices
			::vr::EVRCompositorError eError = m_pCompositor->WaitGetPoses(TrackedDevicePose, ::vr::k_unMaxTrackedDeviceCount, nullptr, 0);
			if (eError != ::vr::EVRCompositorError::VRCompositorError_None)
			{
				std::cout << "Problem with Tracking Updating!\n";
			}

			//TrackedDevicePose[0] is the HMD device ID
			HMDMatrix = glm::inverse(convertToMat4(TrackedDevicePose[0].mDeviceToAbsoluteTracking));

		}
		
		void ShutdownVR()
		{
			::vr::VR_Shutdown();
		}
	}
}