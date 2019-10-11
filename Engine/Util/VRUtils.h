#ifndef VRUTILS_H
#define VRUTILS_H

#include "../Types/Types.h"
#include <openvr.h>
#include <iostream>

namespace vn
{
	namespace vr
	{
		extern mat4 projMatrixL;
		extern mat4 projMatrixR;
		extern mat4 viewMatrixL;
		extern mat4 viewMatrixR;

		extern mat4 HMDMatrix;

		extern ::vr::IVRSystem* m_pHMD;
		extern ::vr::IVRCompositor* m_pCompositor;

		extern ::vr::TrackedDevicePose_t TrackedDevicePose[::vr::k_unMaxTrackedDeviceCount];
		extern mat4 m_rmat4DevicePose[::vr::k_unMaxTrackedDeviceCount];



		inline mat4& convertToMat4(::vr::HmdMatrix44_t mat)
		{
			const float matrix[] =
			{
				mat.m[0][0], mat.m[1][0], mat.m[2][0], mat.m[3][0],
				mat.m[0][1], mat.m[1][1], mat.m[2][1], mat.m[3][1],
				mat.m[0][2], mat.m[1][2], mat.m[2][2], mat.m[3][2],
				mat.m[0][3], mat.m[1][3], mat.m[2][3], mat.m[3][3]
			};
			glm::mat4 out = glm::make_mat4(matrix);
			return out;
		}

		inline mat4& convertToMat4(::vr::HmdMatrix34_t mat)
		{
			const float matrix[] =
			{
				mat.m[0][0], mat.m[1][0], mat.m[2][0], 0.0f,
				mat.m[0][1], mat.m[1][1], mat.m[2][1], 0.0f,
				mat.m[0][2], mat.m[1][2], mat.m[2][2], 0.0f,
				mat.m[0][3], mat.m[1][3], mat.m[2][3], 1.0f
			};
			glm::mat4 out = glm::make_mat4(matrix);
			return out;
		}


		inline mat4 getViewMatrix(::vr::Hmd_Eye nEye)
		{
			return glm::inverse(convertToMat4(m_pHMD->GetEyeToHeadTransform(nEye)));
		}

		inline mat4 getProjMatrix(::vr::Hmd_Eye nEye)
		{
			return convertToMat4(m_pHMD->GetProjectionMatrix(nEye, 0.1f, 1000.0f));
		}

		bool initVR();

		void updateTracking();

		//mat4 deviceMatrix is essentially the model matrix
		inline Transform getDeviceTransform(uint32_t deviceIndex)
		{
			if (TrackedDevicePose[deviceIndex].bDeviceIsConnected && deviceIndex >= ::vr::k_unMaxTrackedDeviceCount)
			{
				return Transform();
			}
			glm::mat4 deviceMatrix = convertToMat4(TrackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			Transform device;

			device.pos = vec3(deviceMatrix[0][3], deviceMatrix[1][3], deviceMatrix[2][3]);
			device.scale = vec3(deviceMatrix[0][0], deviceMatrix[1][1], deviceMatrix[2][2]);
		}

		void ShutdownVR();

		inline vec2 getRecommendedViewportSize()
		{
			uint32_t x, y;
			m_pHMD->GetRecommendedRenderTargetSize(&x, &y);
			return vec2(x, y);
		}

		void printTransformOfDevice(uint32_t deviceIndex);
	}
}

#endif // !VRUTILS_H