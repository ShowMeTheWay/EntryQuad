/*
 * sin_cos.h
 *
 *  Created on: Jul 25, 2017
 *      Author: User
 */

#ifndef SIN_COS_H_
#define SIN_COS_H_

#include "arm_math.h"
#include "cmsis_os.h"

#define ARM_MATH_CM4

void arm_sin_cos_f32(
  float32_t theta,
  float32_t * pSinVal,
  float32_t * pCosVal);



#endif /* SIN_COS_H_ */
