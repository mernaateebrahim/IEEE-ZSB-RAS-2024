/*
 * Bit_math.h
 *
 *  Created on: Jul 11, 2024
 *      Author: Merna Atef
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define MASK_PIN    1

#define SET_BIT(_REG,PIN)      (_REG=_REG | (MASK_PIN <<PIN))
#define CLEAR_BIT(_REG,PIN)    (_REG=_REG & (~(MASK_PIN<<PIN)))
#define TOGGLE_BIT(_REG,PIN)   (_REG=_REG ^ (MASK_PIN<<PIN))
#define READ_BIT(_REG,PIN)     ((_REG>>PIN)  & MASK_PIN)




#endif /* BIT_MATH_H_ */
