/*******************************************************************************
 * LBF_LaunchUSB_MassStorage.c
 * 
 * 
 * Author: La BlueFrog, 2015
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 ******************************************************************************/


#include "usbd_libs.h"
#include "LBF_LaunchUSB_MassStorage.h"
#include "LBF_custom_types.h"

/* Private variables ---------------------------------------------------------*/

USBD_HandleTypeDef USBD_Device;

/* Functions -----------------------------------------------------------------*/


boolean_t  LBF_LaunchUSB_MassStorage(void) 
{

boolean_t  Success = TRUE;


  /* Init MSC Application */
  Success &= ( USBD_Init(&USBD_Device, &MSC_Desc, 0) == USBD_OK ) ;
  
  /* Add Supported Class */
  Success &= ( USBD_RegisterClass(&USBD_Device, USBD_MSC_CLASS) == USBD_OK ) ;
  
  /* Add Storage callbacks for MSC Class */
  Success &= ( USBD_MSC_RegisterStorage(&USBD_Device, &USBD_DISK_fops) == USBD_OK ) ;
  
  /* Start Device Process */
  Success &= ( USBD_Start(&USBD_Device) == USBD_OK );
 

  return Success;
}
 


/***************************************************************END OF FILE****/
