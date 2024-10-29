from generator import asar

C_year_IV = asar.createConstantTemplateFromPhysicalType('C_year_IV', asar.UINT16_T, 0)
C_month_IV = asar.createConstantTemplateFromPhysicalType('C_month_IV', asar.UINT8_T, 0)
C_day_IV = asar.createConstantTemplateFromPhysicalType('C_day_IV', asar.UINT8_T, 0)
C_hour_IV = asar.createConstantTemplateFromPhysicalType('C_hour_IV', asar.UINT8_T, 0)
C_minute_IV = asar.createConstantTemplateFromPhysicalType('C_minute_IV', asar.UINT8_T, 0)
C_second_IV = asar.createConstantTemplateFromPhysicalType('C_second_IV', asar.UINT8_T, 0)
C_VehicleSpeed_IV = asar.createConstantTemplateFromPhysicalType('C_VehicleSpeed_IV', asar.UINT16_T, 0)
C_TachoSpeed_IV = asar.createConstantTemplateFromPhysicalType('C_TachoSpeed_IV', asar.UINT16_T, 0)
C_Led1Sts_IV = asar.createConstantTemplateFromPhysicalType('C_Led1Sts_IV', asar.UINT8_T, 0)
C_Led2Sts_IV = asar.createConstantTemplateFromPhysicalType('C_Led2Sts_IV', asar.UINT8_T, 0)
C_Led3Sts_IV = asar.createConstantTemplateFromPhysicalType('C_Led3Sts_IV', asar.UINT8_T, 0)

COM_D = []
COM_D.append(asar.createDataElementTemplate('year', asar.UINT16_T))
COM_D.append(asar.createDataElementTemplate('month', asar.UINT8_T))
COM_D.append(asar.createDataElementTemplate('day', asar.UINT8_T))
COM_D.append(asar.createDataElementTemplate('hour', asar.UINT8_T))
COM_D.append(asar.createDataElementTemplate('minute', asar.UINT8_T))
COM_D.append(asar.createDataElementTemplate('second', asar.UINT8_T))
COM_D.append(asar.createDataElementTemplate('VehicleSpeed', asar.UINT16_T))
COM_D.append(asar.createDataElementTemplate('TachoSpeed', asar.UINT16_T))
COM_D.append(asar.createDataElementTemplate('Led1Sts', asar.UINT8_T))
COM_D.append(asar.createDataElementTemplate('Led2Sts', asar.UINT8_T))
COM_D.append(asar.createDataElementTemplate('Led3Sts', asar.UINT8_T))

COM_I = asar.createSenderReceiverInterfaceTemplate('Com_I', COM_D)

year = asar.createSenderReceiverPortTemplate('Com', COM_I, C_year_IV, aliveTimeout=30, elemName='year')
month = asar.createSenderReceiverPortTemplate('Com', COM_I, C_month_IV, aliveTimeout=30, elemName='month')
day = asar.createSenderReceiverPortTemplate('Com', COM_I, C_day_IV, aliveTimeout=30, elemName='day')
hour = asar.createSenderReceiverPortTemplate('Com', COM_I, C_hour_IV, aliveTimeout=30, elemName='hour')
minute = asar.createSenderReceiverPortTemplate('Com', COM_I, C_minute_IV, aliveTimeout=30, elemName='minute')
second = asar.createSenderReceiverPortTemplate('Com', COM_I, C_second_IV, aliveTimeout=30, elemName='second')
VehicleSpeed = asar.createSenderReceiverPortTemplate('Com', COM_I, C_VehicleSpeed_IV, aliveTimeout=30, elemName='VehicleSpeed')
TachoSpeed = asar.createSenderReceiverPortTemplate('Com', COM_I, C_TachoSpeed_IV, aliveTimeout=30, elemName='TachoSpeed')
Led1Sts = asar.createSenderReceiverPortTemplate('Com', COM_I, C_Led1Sts_IV, aliveTimeout=30, elemName='Led1Sts')
Led2Sts = asar.createSenderReceiverPortTemplate('Com', COM_I, C_Led2Sts_IV, aliveTimeout=30, elemName='Led2Sts')
Led3Sts = asar.createSenderReceiverPortTemplate('Com', COM_I, C_Led3Sts_IV, aliveTimeout=30, elemName='Led3Sts')