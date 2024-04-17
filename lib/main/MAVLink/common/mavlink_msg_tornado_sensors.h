// MESSAGE TORNADO_SENSORS PACKING

#define MAVLINK_MSG_ID_TORNADO_SENSORS 236

typedef struct __mavlink_tornado_sensors_t
{
 uint32_t time_msec; /*<  Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint32_t static_pressure; /*<  Static Pressure*/
 uint32_t diff_pressure_forward; /*<  Diff Pressure Forward*/
 uint32_t diff_pressure_up; /*<  Diff Pressure Up*/
 uint32_t diff_pressure_side; /*<  Diff Pressure Side*/
 uint16_t humidity; /*<  Humidity*/
 uint16_t temp_sht30; /*<  SHT30 Temp*/
 uint16_t temp_lps; /*<  LPS Temp*/
 uint16_t temp_ds18b20; /*<  DS18B20 Temp*/
 uint16_t temp_forward_ms4425; /*<  MS4425 Forward Temp*/
 uint16_t temp_up_ms4425; /*<  MS4425 Up Temp*/
 uint16_t temp_side_ms4425; /*<  MS4425 Side Temp*/
} mavlink_tornado_sensors_t;

#define MAVLINK_MSG_ID_TORNADO_SENSORS_LEN 34
#define MAVLINK_MSG_ID_TORNADO_SENSORS_MIN_LEN 34
#define MAVLINK_MSG_ID_236_LEN 34
#define MAVLINK_MSG_ID_236_MIN_LEN 34

#define MAVLINK_MSG_ID_TORNADO_SENSORS_CRC 250
#define MAVLINK_MSG_ID_236_CRC 250



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TORNADO_SENSORS { \
    236, \
    "TORNADO_SENSORS", \
    12, \
    {  { "time_msec", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_tornado_sensors_t, time_msec) }, \
         { "humidity", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_tornado_sensors_t, humidity) }, \
         { "temp_sht30", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_tornado_sensors_t, temp_sht30) }, \
         { "static_pressure", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_tornado_sensors_t, static_pressure) }, \
         { "temp_lps", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_tornado_sensors_t, temp_lps) }, \
         { "temp_ds18b20", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_tornado_sensors_t, temp_ds18b20) }, \
         { "diff_pressure_forward", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_tornado_sensors_t, diff_pressure_forward) }, \
         { "temp_forward_ms4425", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_tornado_sensors_t, temp_forward_ms4425) }, \
         { "diff_pressure_up", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_tornado_sensors_t, diff_pressure_up) }, \
         { "temp_up_ms4425", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_tornado_sensors_t, temp_up_ms4425) }, \
         { "diff_pressure_side", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_tornado_sensors_t, diff_pressure_side) }, \
         { "temp_side_ms4425", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_tornado_sensors_t, temp_side_ms4425) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TORNADO_SENSORS { \
    "TORNADO_SENSORS", \
    12, \
    {  { "time_msec", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_tornado_sensors_t, time_msec) }, \
         { "humidity", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_tornado_sensors_t, humidity) }, \
         { "temp_sht30", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_tornado_sensors_t, temp_sht30) }, \
         { "static_pressure", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_tornado_sensors_t, static_pressure) }, \
         { "temp_lps", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_tornado_sensors_t, temp_lps) }, \
         { "temp_ds18b20", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_tornado_sensors_t, temp_ds18b20) }, \
         { "diff_pressure_forward", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_tornado_sensors_t, diff_pressure_forward) }, \
         { "temp_forward_ms4425", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_tornado_sensors_t, temp_forward_ms4425) }, \
         { "diff_pressure_up", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_tornado_sensors_t, diff_pressure_up) }, \
         { "temp_up_ms4425", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_tornado_sensors_t, temp_up_ms4425) }, \
         { "diff_pressure_side", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_tornado_sensors_t, diff_pressure_side) }, \
         { "temp_side_ms4425", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_tornado_sensors_t, temp_side_ms4425) }, \
         } \
}
#endif

/**
 * @brief Pack a tornado_sensors message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_msec  Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param humidity  Humidity
 * @param temp_sht30  SHT30 Temp
 * @param static_pressure  Static Pressure
 * @param temp_lps  LPS Temp
 * @param temp_ds18b20  DS18B20 Temp
 * @param diff_pressure_forward  Diff Pressure Forward
 * @param temp_forward_ms4425  MS4425 Forward Temp
 * @param diff_pressure_up  Diff Pressure Up
 * @param temp_up_ms4425  MS4425 Up Temp
 * @param diff_pressure_side  Diff Pressure Side
 * @param temp_side_ms4425  MS4425 Side Temp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tornado_sensors_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_msec, uint16_t humidity, uint16_t temp_sht30, uint32_t static_pressure, uint16_t temp_lps, uint16_t temp_ds18b20, uint32_t diff_pressure_forward, uint16_t temp_forward_ms4425, uint32_t diff_pressure_up, uint16_t temp_up_ms4425, uint32_t diff_pressure_side, uint16_t temp_side_ms4425)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TORNADO_SENSORS_LEN];
    _mav_put_uint32_t(buf, 0, time_msec);
    _mav_put_uint32_t(buf, 4, static_pressure);
    _mav_put_uint32_t(buf, 8, diff_pressure_forward);
    _mav_put_uint32_t(buf, 12, diff_pressure_up);
    _mav_put_uint32_t(buf, 16, diff_pressure_side);
    _mav_put_uint16_t(buf, 20, humidity);
    _mav_put_uint16_t(buf, 22, temp_sht30);
    _mav_put_uint16_t(buf, 24, temp_lps);
    _mav_put_uint16_t(buf, 26, temp_ds18b20);
    _mav_put_uint16_t(buf, 28, temp_forward_ms4425);
    _mav_put_uint16_t(buf, 30, temp_up_ms4425);
    _mav_put_uint16_t(buf, 32, temp_side_ms4425);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN);
#else
    mavlink_tornado_sensors_t packet;
    packet.time_msec = time_msec;
    packet.static_pressure = static_pressure;
    packet.diff_pressure_forward = diff_pressure_forward;
    packet.diff_pressure_up = diff_pressure_up;
    packet.diff_pressure_side = diff_pressure_side;
    packet.humidity = humidity;
    packet.temp_sht30 = temp_sht30;
    packet.temp_lps = temp_lps;
    packet.temp_ds18b20 = temp_ds18b20;
    packet.temp_forward_ms4425 = temp_forward_ms4425;
    packet.temp_up_ms4425 = temp_up_ms4425;
    packet.temp_side_ms4425 = temp_side_ms4425;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TORNADO_SENSORS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN, MAVLINK_MSG_ID_TORNADO_SENSORS_CRC);
}

/**
 * @brief Pack a tornado_sensors message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_msec  Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param humidity  Humidity
 * @param temp_sht30  SHT30 Temp
 * @param static_pressure  Static Pressure
 * @param temp_lps  LPS Temp
 * @param temp_ds18b20  DS18B20 Temp
 * @param diff_pressure_forward  Diff Pressure Forward
 * @param temp_forward_ms4425  MS4425 Forward Temp
 * @param diff_pressure_up  Diff Pressure Up
 * @param temp_up_ms4425  MS4425 Up Temp
 * @param diff_pressure_side  Diff Pressure Side
 * @param temp_side_ms4425  MS4425 Side Temp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
// static inline uint16_t mavlink_msg_tornado_sensors_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
//                                uint32_t time_msec, uint16_t humidity, uint16_t temp_sht30, uint32_t static_pressure, uint16_t temp_lps, uint16_t temp_ds18b20, uint32_t diff_pressure_forward, uint16_t temp_forward_ms4425, uint32_t diff_pressure_up, uint16_t temp_up_ms4425, uint32_t diff_pressure_side, uint16_t temp_side_ms4425)
// {
// #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
//     char buf[MAVLINK_MSG_ID_TORNADO_SENSORS_LEN];
//     _mav_put_uint32_t(buf, 0, time_msec);
//     _mav_put_uint32_t(buf, 4, static_pressure);
//     _mav_put_uint32_t(buf, 8, diff_pressure_forward);
//     _mav_put_uint32_t(buf, 12, diff_pressure_up);
//     _mav_put_uint32_t(buf, 16, diff_pressure_side);
//     _mav_put_uint16_t(buf, 20, humidity);
//     _mav_put_uint16_t(buf, 22, temp_sht30);
//     _mav_put_uint16_t(buf, 24, temp_lps);
//     _mav_put_uint16_t(buf, 26, temp_ds18b20);
//     _mav_put_uint16_t(buf, 28, temp_forward_ms4425);
//     _mav_put_uint16_t(buf, 30, temp_up_ms4425);
//     _mav_put_uint16_t(buf, 32, temp_side_ms4425);

//         memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN);
// #else
//     mavlink_tornado_sensors_t packet;
//     packet.time_msec = time_msec;
//     packet.static_pressure = static_pressure;
//     packet.diff_pressure_forward = diff_pressure_forward;
//     packet.diff_pressure_up = diff_pressure_up;
//     packet.diff_pressure_side = diff_pressure_side;
//     packet.humidity = humidity;
//     packet.temp_sht30 = temp_sht30;
//     packet.temp_lps = temp_lps;
//     packet.temp_ds18b20 = temp_ds18b20;
//     packet.temp_forward_ms4425 = temp_forward_ms4425;
//     packet.temp_up_ms4425 = temp_up_ms4425;
//     packet.temp_side_ms4425 = temp_side_ms4425;

//         memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN);
// #endif

//     msg->msgid = MAVLINK_MSG_ID_TORNADO_SENSORS;
// #if MAVLINK_CRC_EXTRA
//     return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN, MAVLINK_MSG_ID_TORNADO_SENSORS_CRC);
// #else
//     return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN);
// #endif
// }

/**
 * @brief Pack a tornado_sensors message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_msec  Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param humidity  Humidity
 * @param temp_sht30  SHT30 Temp
 * @param static_pressure  Static Pressure
 * @param temp_lps  LPS Temp
 * @param temp_ds18b20  DS18B20 Temp
 * @param diff_pressure_forward  Diff Pressure Forward
 * @param temp_forward_ms4425  MS4425 Forward Temp
 * @param diff_pressure_up  Diff Pressure Up
 * @param temp_up_ms4425  MS4425 Up Temp
 * @param diff_pressure_side  Diff Pressure Side
 * @param temp_side_ms4425  MS4425 Side Temp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tornado_sensors_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_msec,uint16_t humidity,uint16_t temp_sht30,uint32_t static_pressure,uint16_t temp_lps,uint16_t temp_ds18b20,uint32_t diff_pressure_forward,uint16_t temp_forward_ms4425,uint32_t diff_pressure_up,uint16_t temp_up_ms4425,uint32_t diff_pressure_side,uint16_t temp_side_ms4425)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TORNADO_SENSORS_LEN];
    _mav_put_uint32_t(buf, 0, time_msec);
    _mav_put_uint32_t(buf, 4, static_pressure);
    _mav_put_uint32_t(buf, 8, diff_pressure_forward);
    _mav_put_uint32_t(buf, 12, diff_pressure_up);
    _mav_put_uint32_t(buf, 16, diff_pressure_side);
    _mav_put_uint16_t(buf, 20, humidity);
    _mav_put_uint16_t(buf, 22, temp_sht30);
    _mav_put_uint16_t(buf, 24, temp_lps);
    _mav_put_uint16_t(buf, 26, temp_ds18b20);
    _mav_put_uint16_t(buf, 28, temp_forward_ms4425);
    _mav_put_uint16_t(buf, 30, temp_up_ms4425);
    _mav_put_uint16_t(buf, 32, temp_side_ms4425);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN);
#else
    mavlink_tornado_sensors_t packet;
    packet.time_msec = time_msec;
    packet.static_pressure = static_pressure;
    packet.diff_pressure_forward = diff_pressure_forward;
    packet.diff_pressure_up = diff_pressure_up;
    packet.diff_pressure_side = diff_pressure_side;
    packet.humidity = humidity;
    packet.temp_sht30 = temp_sht30;
    packet.temp_lps = temp_lps;
    packet.temp_ds18b20 = temp_ds18b20;
    packet.temp_forward_ms4425 = temp_forward_ms4425;
    packet.temp_up_ms4425 = temp_up_ms4425;
    packet.temp_side_ms4425 = temp_side_ms4425;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TORNADO_SENSORS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN, MAVLINK_MSG_ID_TORNADO_SENSORS_CRC);
}

/**
 * @brief Encode a tornado_sensors struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tornado_sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tornado_sensors_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tornado_sensors_t* tornado_sensors)
{
    return mavlink_msg_tornado_sensors_pack(system_id, component_id, msg, tornado_sensors->time_msec, tornado_sensors->humidity, tornado_sensors->temp_sht30, tornado_sensors->static_pressure, tornado_sensors->temp_lps, tornado_sensors->temp_ds18b20, tornado_sensors->diff_pressure_forward, tornado_sensors->temp_forward_ms4425, tornado_sensors->diff_pressure_up, tornado_sensors->temp_up_ms4425, tornado_sensors->diff_pressure_side, tornado_sensors->temp_side_ms4425);
}

/**
 * @brief Encode a tornado_sensors struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tornado_sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tornado_sensors_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tornado_sensors_t* tornado_sensors)
{
    return mavlink_msg_tornado_sensors_pack_chan(system_id, component_id, chan, msg, tornado_sensors->time_msec, tornado_sensors->humidity, tornado_sensors->temp_sht30, tornado_sensors->static_pressure, tornado_sensors->temp_lps, tornado_sensors->temp_ds18b20, tornado_sensors->diff_pressure_forward, tornado_sensors->temp_forward_ms4425, tornado_sensors->diff_pressure_up, tornado_sensors->temp_up_ms4425, tornado_sensors->diff_pressure_side, tornado_sensors->temp_side_ms4425);
}

/**
 * @brief Encode a tornado_sensors struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param tornado_sensors C-struct to read the message contents from
 */
// static inline uint16_t mavlink_msg_tornado_sensors_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_tornado_sensors_t* tornado_sensors)
// {
//     return mavlink_msg_tornado_sensors_pack_status(system_id, component_id, _status, msg,  tornado_sensors->time_msec, tornado_sensors->humidity, tornado_sensors->temp_sht30, tornado_sensors->static_pressure, tornado_sensors->temp_lps, tornado_sensors->temp_ds18b20, tornado_sensors->diff_pressure_forward, tornado_sensors->temp_forward_ms4425, tornado_sensors->diff_pressure_up, tornado_sensors->temp_up_ms4425, tornado_sensors->diff_pressure_side, tornado_sensors->temp_side_ms4425);
// }

/**
 * @brief Send a tornado_sensors message
 * @param chan MAVLink channel to send the message
 *
 * @param time_msec  Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param humidity  Humidity
 * @param temp_sht30  SHT30 Temp
 * @param static_pressure  Static Pressure
 * @param temp_lps  LPS Temp
 * @param temp_ds18b20  DS18B20 Temp
 * @param diff_pressure_forward  Diff Pressure Forward
 * @param temp_forward_ms4425  MS4425 Forward Temp
 * @param diff_pressure_up  Diff Pressure Up
 * @param temp_up_ms4425  MS4425 Up Temp
 * @param diff_pressure_side  Diff Pressure Side
 * @param temp_side_ms4425  MS4425 Side Temp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tornado_sensors_send(mavlink_channel_t chan, uint32_t time_msec, uint16_t humidity, uint16_t temp_sht30, uint32_t static_pressure, uint16_t temp_lps, uint16_t temp_ds18b20, uint32_t diff_pressure_forward, uint16_t temp_forward_ms4425, uint32_t diff_pressure_up, uint16_t temp_up_ms4425, uint32_t diff_pressure_side, uint16_t temp_side_ms4425)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TORNADO_SENSORS_LEN];
    _mav_put_uint32_t(buf, 0, time_msec);
    _mav_put_uint32_t(buf, 4, static_pressure);
    _mav_put_uint32_t(buf, 8, diff_pressure_forward);
    _mav_put_uint32_t(buf, 12, diff_pressure_up);
    _mav_put_uint32_t(buf, 16, diff_pressure_side);
    _mav_put_uint16_t(buf, 20, humidity);
    _mav_put_uint16_t(buf, 22, temp_sht30);
    _mav_put_uint16_t(buf, 24, temp_lps);
    _mav_put_uint16_t(buf, 26, temp_ds18b20);
    _mav_put_uint16_t(buf, 28, temp_forward_ms4425);
    _mav_put_uint16_t(buf, 30, temp_up_ms4425);
    _mav_put_uint16_t(buf, 32, temp_side_ms4425);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TORNADO_SENSORS, buf, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN, MAVLINK_MSG_ID_TORNADO_SENSORS_CRC);
#else
    mavlink_tornado_sensors_t packet;
    packet.time_msec = time_msec;
    packet.static_pressure = static_pressure;
    packet.diff_pressure_forward = diff_pressure_forward;
    packet.diff_pressure_up = diff_pressure_up;
    packet.diff_pressure_side = diff_pressure_side;
    packet.humidity = humidity;
    packet.temp_sht30 = temp_sht30;
    packet.temp_lps = temp_lps;
    packet.temp_ds18b20 = temp_ds18b20;
    packet.temp_forward_ms4425 = temp_forward_ms4425;
    packet.temp_up_ms4425 = temp_up_ms4425;
    packet.temp_side_ms4425 = temp_side_ms4425;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TORNADO_SENSORS, (const char *)&packet, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN, MAVLINK_MSG_ID_TORNADO_SENSORS_CRC);
#endif
}

/**
 * @brief Send a tornado_sensors message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tornado_sensors_send_struct(mavlink_channel_t chan, const mavlink_tornado_sensors_t* tornado_sensors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tornado_sensors_send(chan, tornado_sensors->time_msec, tornado_sensors->humidity, tornado_sensors->temp_sht30, tornado_sensors->static_pressure, tornado_sensors->temp_lps, tornado_sensors->temp_ds18b20, tornado_sensors->diff_pressure_forward, tornado_sensors->temp_forward_ms4425, tornado_sensors->diff_pressure_up, tornado_sensors->temp_up_ms4425, tornado_sensors->diff_pressure_side, tornado_sensors->temp_side_ms4425);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TORNADO_SENSORS, (const char *)tornado_sensors, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN, MAVLINK_MSG_ID_TORNADO_SENSORS_CRC);
#endif
}

#if MAVLINK_MSG_ID_TORNADO_SENSORS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tornado_sensors_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_msec, uint16_t humidity, uint16_t temp_sht30, uint32_t static_pressure, uint16_t temp_lps, uint16_t temp_ds18b20, uint32_t diff_pressure_forward, uint16_t temp_forward_ms4425, uint32_t diff_pressure_up, uint16_t temp_up_ms4425, uint32_t diff_pressure_side, uint16_t temp_side_ms4425)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_msec);
    _mav_put_uint32_t(buf, 4, static_pressure);
    _mav_put_uint32_t(buf, 8, diff_pressure_forward);
    _mav_put_uint32_t(buf, 12, diff_pressure_up);
    _mav_put_uint32_t(buf, 16, diff_pressure_side);
    _mav_put_uint16_t(buf, 20, humidity);
    _mav_put_uint16_t(buf, 22, temp_sht30);
    _mav_put_uint16_t(buf, 24, temp_lps);
    _mav_put_uint16_t(buf, 26, temp_ds18b20);
    _mav_put_uint16_t(buf, 28, temp_forward_ms4425);
    _mav_put_uint16_t(buf, 30, temp_up_ms4425);
    _mav_put_uint16_t(buf, 32, temp_side_ms4425);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TORNADO_SENSORS, buf, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN, MAVLINK_MSG_ID_TORNADO_SENSORS_CRC);
#else
    mavlink_tornado_sensors_t *packet = (mavlink_tornado_sensors_t *)msgbuf;
    packet->time_msec = time_msec;
    packet->static_pressure = static_pressure;
    packet->diff_pressure_forward = diff_pressure_forward;
    packet->diff_pressure_up = diff_pressure_up;
    packet->diff_pressure_side = diff_pressure_side;
    packet->humidity = humidity;
    packet->temp_sht30 = temp_sht30;
    packet->temp_lps = temp_lps;
    packet->temp_ds18b20 = temp_ds18b20;
    packet->temp_forward_ms4425 = temp_forward_ms4425;
    packet->temp_up_ms4425 = temp_up_ms4425;
    packet->temp_side_ms4425 = temp_side_ms4425;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TORNADO_SENSORS, (const char *)packet, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN, MAVLINK_MSG_ID_TORNADO_SENSORS_CRC);
#endif
}
#endif

#endif

// MESSAGE TORNADO_SENSORS UNPACKING


/**
 * @brief Get field time_msec from tornado_sensors message
 *
 * @return  Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint32_t mavlink_msg_tornado_sensors_get_time_msec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field humidity from tornado_sensors message
 *
 * @return  Humidity
 */
static inline uint16_t mavlink_msg_tornado_sensors_get_humidity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field temp_sht30 from tornado_sensors message
 *
 * @return  SHT30 Temp
 */
static inline uint16_t mavlink_msg_tornado_sensors_get_temp_sht30(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field static_pressure from tornado_sensors message
 *
 * @return  Static Pressure
 */
static inline uint32_t mavlink_msg_tornado_sensors_get_static_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field temp_lps from tornado_sensors message
 *
 * @return  LPS Temp
 */
static inline uint16_t mavlink_msg_tornado_sensors_get_temp_lps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field temp_ds18b20 from tornado_sensors message
 *
 * @return  DS18B20 Temp
 */
static inline uint16_t mavlink_msg_tornado_sensors_get_temp_ds18b20(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field diff_pressure_forward from tornado_sensors message
 *
 * @return  Diff Pressure Forward
 */
static inline uint32_t mavlink_msg_tornado_sensors_get_diff_pressure_forward(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field temp_forward_ms4425 from tornado_sensors message
 *
 * @return  MS4425 Forward Temp
 */
static inline uint16_t mavlink_msg_tornado_sensors_get_temp_forward_ms4425(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field diff_pressure_up from tornado_sensors message
 *
 * @return  Diff Pressure Up
 */
static inline uint32_t mavlink_msg_tornado_sensors_get_diff_pressure_up(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field temp_up_ms4425 from tornado_sensors message
 *
 * @return  MS4425 Up Temp
 */
static inline uint16_t mavlink_msg_tornado_sensors_get_temp_up_ms4425(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field diff_pressure_side from tornado_sensors message
 *
 * @return  Diff Pressure Side
 */
static inline uint32_t mavlink_msg_tornado_sensors_get_diff_pressure_side(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field temp_side_ms4425 from tornado_sensors message
 *
 * @return  MS4425 Side Temp
 */
static inline uint16_t mavlink_msg_tornado_sensors_get_temp_side_ms4425(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Decode a tornado_sensors message into a struct
 *
 * @param msg The message to decode
 * @param tornado_sensors C-struct to decode the message contents into
 */
static inline void mavlink_msg_tornado_sensors_decode(const mavlink_message_t* msg, mavlink_tornado_sensors_t* tornado_sensors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tornado_sensors->time_msec = mavlink_msg_tornado_sensors_get_time_msec(msg);
    tornado_sensors->static_pressure = mavlink_msg_tornado_sensors_get_static_pressure(msg);
    tornado_sensors->diff_pressure_forward = mavlink_msg_tornado_sensors_get_diff_pressure_forward(msg);
    tornado_sensors->diff_pressure_up = mavlink_msg_tornado_sensors_get_diff_pressure_up(msg);
    tornado_sensors->diff_pressure_side = mavlink_msg_tornado_sensors_get_diff_pressure_side(msg);
    tornado_sensors->humidity = mavlink_msg_tornado_sensors_get_humidity(msg);
    tornado_sensors->temp_sht30 = mavlink_msg_tornado_sensors_get_temp_sht30(msg);
    tornado_sensors->temp_lps = mavlink_msg_tornado_sensors_get_temp_lps(msg);
    tornado_sensors->temp_ds18b20 = mavlink_msg_tornado_sensors_get_temp_ds18b20(msg);
    tornado_sensors->temp_forward_ms4425 = mavlink_msg_tornado_sensors_get_temp_forward_ms4425(msg);
    tornado_sensors->temp_up_ms4425 = mavlink_msg_tornado_sensors_get_temp_up_ms4425(msg);
    tornado_sensors->temp_side_ms4425 = mavlink_msg_tornado_sensors_get_temp_side_ms4425(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TORNADO_SENSORS_LEN? msg->len : MAVLINK_MSG_ID_TORNADO_SENSORS_LEN;
        memset(tornado_sensors, 0, MAVLINK_MSG_ID_TORNADO_SENSORS_LEN);
    memcpy(tornado_sensors, _MAV_PAYLOAD(msg), len);
#endif
}