#pragma once

#include "mavlink_include.h"
#include "plugins/mission/mission_item.h"

namespace mavsdk {

class MissionItemImpl {
public:
    MissionItemImpl();
    ~MissionItemImpl();

    void set_position(double latitude_deg, double longitude_deg);
    void set_relative_altitude(float relative_altitude_m);
    void set_speed(float speed_m_s);
    void set_fly_through(bool fly_through);
    void set_acceptance_radius(float radius_m);
    void set_gimbal_pitch_and_yaw(float pitch_deg, float yaw_deg);
    void set_loiter_time(float loiter_time_s);
    void set_camera_action(MissionItem::CameraAction action);
    void set_camera_photo_interval(double interval_s);

    /* Addition for trajectory planning -> param3 is payload weight and param4 is deadline */
    void set_mavlink_param3(float payloadWeight);
    void set_mavlink_param4(float deadline);

    double get_latitude_deg() const { return _latitude_deg; }
    double get_longitude_deg() const { return _longitude_deg; }
    float get_relative_altitude_m() const { return _relative_altitude_m; }
    float get_speed_m_s() const { return _speed_m_s; }
    bool get_fly_through() const { return _fly_through; };
    float get_acceptance_radius_m() const { return _acceptance_radius_m; };
    float get_gimbal_pitch_deg() const { return _gimbal_pitch_deg; }
    float get_gimbal_yaw_deg() const { return _gimbal_yaw_deg; }
    float get_loiter_time_s() const { return _loiter_time_s; }
    MissionItem::CameraAction get_camera_action() const { return _camera_action; }
    double get_camera_photo_interval_s() const { return _camera_photo_interval_s; }

    MAV_FRAME get_mavlink_frame() const;
    MAV_CMD get_mavlink_cmd() const;
    uint8_t get_mavlink_autocontinue() const;
    float get_mavlink_param1() const;
    float get_mavlink_param2() const;
    //float get_mavlink_param3() const;
    //float get_mavlink_param4() const;
    float get_mavlink_param3();
    float get_mavlink_param4();

    int32_t get_mavlink_x() const;
    int32_t get_mavlink_y() const;
    float get_mavlink_z() const;
    bool is_position_finite() const;

private:
    double _latitude_deg = double(NAN);
    double _longitude_deg = double(NAN);
    float _relative_altitude_m = NAN;
    float _speed_m_s = NAN;
    bool _fly_through = false;
    float _acceptance_radius_m = NAN;
    float _gimbal_pitch_deg = NAN;
    float _gimbal_yaw_deg = NAN;
    float _loiter_time_s = NAN;
    MissionItem::CameraAction _camera_action{MissionItem::CameraAction::NONE};
    double _camera_photo_interval_s = 1.0;

    float _param3 = NAN;
    float _param4 = NAN;
};

} // namespace mavsdk
