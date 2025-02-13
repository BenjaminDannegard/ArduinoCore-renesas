#ifndef ARDUINO_REAL_TIME_CLOCK
#define ARDUINO_REAL_TIME_CLOCK

#include <ctime>
#include "r_rtc_api.h"
#include <api/String.h>

struct timeval
{
    time_t tv_sec;
    useconds_t tv_usec;
};

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Sets the system time.
     *
     * This function sets the system time to the specified value.
     * The time is provided as a `time_t` object, representing the
     * number of seconds since the Unix epoch (January 1, 1970).
     *
     * @param `t` The time to set, expressed as a `time_t` object.
     * This value represents the number of seconds since
     * the Unix epoch.
     */
    void set_time(time_t t);

    /**
     * @brief Attaches RTC (Real-Time Clock) handling functions.
     *
     * This function attaches custom handlers for reading, writing, initializing,
     * and checking the status of the RTC. These handlers allow integration with
     * an external RTC module or custom RTC implementation.
     *
     * @param `read_rtc` A pointer to a function that reads the current RTC time
     * and returns it as a `time_t` value.
     * @param `write_rtc` A pointer to a function that sets the RTC time to the
     * specified `time_t` value.
     * @param `init_rtc` A pointer to a function that initializes the RTC hardware.
     * @param `isenabled_rtc` A pointer to a function that checks whether the RTC
     * is enabled, returning an integer (e.g., 1 for enabled, 0 for disabled).
     */
    void attach_rtc(time_t (*read_rtc)(void), void (*write_rtc)(time_t), void (*init_rtc)(void), int (*isenabled_rtc)(void));

    /**
     * @brief Retrieves the current time of day.
     *
     * This function gets the current time, expressed as seconds and microseconds
     * since the Unix epoch (00:00:00 UTC, January 1, 1970). The time is stored in
     * a `timeval` structure.
     *
     * @param `tv` A pointer to a `timeval` structure where the current time will be stored.
     * The structure contains two fields:
     *  - `tv_sec`: Seconds since the Unix epoch.
     *  - `tv_usec`: Microseconds since the last second.
     * @param `tz` A pointer to a timezone structure (optional). It is usually set to `nullptr`
     * as timezone information is not handled by this function on most systems.
     *
     * @return Returns `0` on success, or `-1` on failure (e.g., if `tv` is `nullptr`).
     */
    int gettimeofday(struct timeval *tv, void *tz);

    /**
     * @brief Sets the current time of day and timezone.
     *
     * This function sets the system's current time and optionally the timezone.
     * The new time is specified in a `timeval` structure, which contains the
     * number of seconds and microseconds since the Unix epoch (00:00:00 UTC,
     * January 1, 1970).
     *
     * @param `tv` A pointer to a `timeval` structure specifying the new time.
     * The structure contains two fields:
     *  - `tv_sec`: Seconds since the Unix epoch.
     *  - `tv_usec`: Microseconds since the last second.
     * @param `tz` A pointer to a `timezone` structure specifying the timezone (optional).
     *
     * @return Returns `0` on success, or `-1` on failure (e.g., if `tv` is `nullptr` or the operation is not permitted).
     */
    int settimeofday(const struct timeval *tv, const struct timezone *tz);

#ifdef __cplusplus
}
#endif

using stime_t = struct tm;
using rtc_cbk_t = void (*)();

/**
 * @brief Enumeration representing the months of the year.
 *
 * This enumeration maps the months of the year to numeric values, starting from 0 for January and ending at 11 for December.
 */
enum class Month : uint8_t
{
    JANUARY = 0,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

/**
 * @brief Converts a `Month` enumeration value to its corresponding integer representation.
 *
 * This function takes a `Month` enumeration value and returns its integer equivalent.
 *
 * @param `m` The `Month` enumeration value to convert.
 *
 * @return The integer representation of the given month.
 */
int Month2int(Month m);

/**
 * @brief Enumeration representing the days of the week.
 *
 * This enumeration maps the days of the week to numeric values.
 */
enum class DayOfWeek : uint8_t
{
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
    SUNDAY = 0
};

/**
 * @brief Converts a `DayOfWeek` enumeration value to its corresponding integer representation.
 *
 * This function maps a `DayOfWeek` enumeration value to an integer representation based on
 * whether Sunday or Monday is considered the first day of the week.
 *
 * @param `dow` The `DayOfWeek` enumeration value to convert.
 * @param `sunday_first` A boolean flag that determines the starting day of the week:
 *  - `true`: Sunday is the first day of the week (Sunday = 0, Monday = 1, ...).
 *  - `false`: Monday is the first day of the week (Monday = 0, Tuesday = 1, ...).
 *
 * @return The integer representation of the given day of the week, adjusted based on
 * the value of `sunday_first`.
 */
int DayOfWeek2int(DayOfWeek dow, bool sunday_first);

enum class SaveLight : uint8_t
{
    SAVING_TIME_INACTIVE = 0,
    SAVING_TIME_ACTIVE

};

/**
 * @brief Converts a `SaveLight` enumeration value to its corresponding boolean representation.
 *
 * This function maps a `SaveLight` enumeration value to a boolean, used to indicate
 * whether it is daylight savings time (`true`) or not (`false`).
 *
 * @param `sl` The `SaveLight` enumeration value to convert.
 *
 * @return `true` if it is daylight savings time, `false` otherwise.
 */
bool SaveLigth2bool(SaveLight sl);

/**
 * @brief A class representing time in the context of an RTC (Real-Time Clock).
 *
 * The `RTCTime` class encapsulates time-related information and provides utility methods
 * to interact with and manipulate RTC time.
 */
class RTCTime
{
private:
    stime_t stime;

    int day;
    Month month;
    int year;
    int hours;
    int minutes;
    int seconds;
    DayOfWeek day_of_week;
    SaveLight save_light;

public:
    /**
     * @brief Default constructor for the RTCTime class.
     */
    RTCTime();

    /**
     * @brief Constructor for the RTCTime class with a given time.
     *
     * Initializes the RTCTime object with the specified time.
     *
     * @param `t` A time_t value representing the time to initialize the RTCTime object with.
     */
    RTCTime(time_t t);

    /**
     * @brief Constructor for the RTCTime class with a given `tm` structure.
     *
     * @param `t` A reference to a struct `tm` that contains the broken-down time to initialize the RTCTime object with.
     */
    RTCTime(struct tm &t);

    /**
     * @brief Constructor for the RTCTime class with specific date and time parameters.
     *
     * Initializes the RTCTime object with the specified date, time, day of the week, and daylight saving time status.
     *
     * @param `_day` The day of the month.
     * @param `_m` The month of the year (using the Month enum, e.g., JANUARY, FEBRUARY, etc.).
     * @param `_year` The year (e.g., 2024).
     * @param `_hours` The hour of the day (0-23).
     * @param `_minutes` The minute of the hour (0-59).
     * @param `_seconds` The second of the minute (0-59).
     * @param `_dof` The day of the week (using the DayOfWeek enum, e.g., MONDAY, TUESDAY, etc.).
     * @param `_sl` The daylight saving time status (using the SaveLight enum, e.g., DST_ON, DST_OFF).
     */
    RTCTime(int _day, Month _m, int _year, int _hours, int _minutes, int _seconds, DayOfWeek _dof, SaveLight _sl);

    /**
     * @brief Destructor for the RTCTime class.
     */
    ~RTCTime();

    /* setters */
    /**
     * @brief Sets the day of the month.
     *
     * @param `day` The day of the month.
     *
     * @return `true` if the day is set successfully, `false` if the day is out of range.
     */
    bool setDayOfMonth(int day);

    /**
     * @brief Sets the month of the year.
     *
     * @param `m` The month.
     *
     * @return `true` if the month is set successfully, `false` if the month is out of range.
     */
    bool setMonthOfYear(Month m);

    /**
     * @brief Sets the year.
     *
     * @param `year` The year (e.g., 1989 or 2022).
     *
     * @return `true` if the year is set successfully, `false` if the year is invalid.
     */
    bool setYear(int year);

    /**
     * @brief Sets the hour of the day.
     *
     * @param `hour` The hour.
     *
     * @return `true` if the hour is set successfully, `false` if the hour is out of range.
     */
    bool setHour(int hour);

    /**
     * @brief Sets the minute of the hour.
     *
     * @param `minute` The minute.
     *
     * @return `true` if the minute is set successfully, `false` if the minute is out of range.
     */
    bool setMinute(int minute);

    /**
     * @brief Sets the second of the minute.
     *
     * @param `second` The second.
     *
     * @return `true` if the second is set successfully, `false` if the second is out of range.
     */
    bool setSecond(int second);

    /**
     * @brief Sets the day of the week.
     *
     * @param `d` The day of the week (from the DayOfWeek enumeration).
     *
     * @return `true` if the day of the week is set successfully, `false` if the value is invalid.
     */
    bool setDayOfWeek(DayOfWeek d);

    /**
     * @brief Sets whether daylight saving time is active.
     *
     * @param `sl` The SaveLight enumeration value.
     *
     * @return `true` if the daylight saving time setting is applied successfully, `false` otherwise.
     */
    bool setSaveLight(SaveLight sl);

    /**
     * @brief Sets the time using a Unix timestamp.
     *
     * @param `time` The Unix timestamp (seconds since January 1, 1970).
     *
     * @return `true` if the Unix timestamp is set successfully, `false` otherwise.
     */
    bool setUnixTime(time_t time);

    /**
     * @brief Sets the time from a struct tm.
     *
     * @param `t` A reference to a struct tm that contains the time values.
     */
    void setTM(struct tm &t);

    /* Getters */
    /**
     * @brief Gets the day of the month.
     *
     * @return The day of the month.
     */
    int getDayOfMonth() const;

    /**
     * @brief Gets the month of the year.
     *
     * @return The month.
     */
    Month getMonth() const;

    /**
     * @brief Gets the year.
     *
     * @return The year.
     */
    int getYear() const;

    /**
     * @brief Gets the hour of the day.
     *
     * @return The hour.
     */
    int getHour() const;

    /**
     * @brief Gets the minutes of the hour.
     *
     * @return The minutes.
     */
    int getMinutes() const;

    /**
     * @brief Gets the seconds of the minute.
     *
     * @return The seconds.
     */
    int getSeconds() const;

    /**
     * @brief Gets the day of the week.
     *
     * @return The day of the week.
     */
    DayOfWeek getDayOfWeek() const;

    /**
     * @brief Gets the Unix timestamp.
     *
     * @return The Unix timestamp.
     */
    time_t getUnixTime();

    /**
     * @brief Gets the time as a struct `tm`.
     *
     * @return A struct `tm` that contains the time values.
     */
    struct tm getTmTime();

    /**
     * @brief Returns the ISO 8601 string representation of the date and time.
     *
     * @return String The date and time in the format YYYY-MM-DDTHH:MM:SS.
     */
    arduino::String toString() const;

    /**
     * @brief Returns the ISO 8601 string representation of the date and time
     * by calling the toString() method.
     * @return String The date and time in the format YYYY-MM-DDTHH:MM:SS.
     */
    operator arduino::String() const;
};

/**
 * @brief Enum class representing different time periods for periodic events.
 *
 * This enum defines various periods, which represent how often an event occurs in a given second.
 * Each value indicates a multiplier for how many times an event occurs in a second.
 */
enum class Period
{
    ONCE_EVERY_2_SEC,
    ONCE_EVERY_1_SEC,
    N2_TIMES_EVERY_SEC,
    N4_TIMES_EVERY_SEC,
    N8_TIMES_EVERY_SEC,
    N16_TIMES_EVERY_SEC,
    N32_TIMES_EVERY_SEC,
    N64_TIMES_EVERY_SEC,
    N128_TIMES_EVERY_SEC,
    N256_TIMES_EVERY_SEC
};

/**
 * @brief Class representing the alarm match system.
 *
 * This class is used to define how an alarm matches a set of conditions or criteria
 * to trigger an action, such as a timer or event.
 */
class AlarmMatch
{
private:
    unsigned int match;

public:
    /**
     * @brief Default constructor for the AlarmMatch class.
     */
    AlarmMatch();

    /**
     * @brief Destructor for the AlarmMatch class.
     */
    ~AlarmMatch();

    /**
     * @brief Increments the match time by one second.
     *
     * This function updates the internal match time by adding one second to the
     * current value.
     */
    void addMatchSecond();

    /**
     * @brief Increments the match time by one minute.
     *
     * This function updates the internal match time by adding one minute to the
     * current value.
     */
    void addMatchMinute();

    /**
     * @brief Increments the match time by one hour.
     *
     * This function updates the internal match time by adding one hour to the
     * current value.
     */
    void addMatchHour();

    /**
     * @brief Increments the match time by one day.
     *
     * This function updates the internal match time by adding one day to the
     * current value.
     */
    void addMatchDay();

    /**
     * @brief Increments the match time by one month.
     *
     * This function updates the internal match time by adding one month to the
     * current value.
     */
    void addMatchMonth();

    /**
     * @brief Increments the match time by one year.
     *
     * This function updates the internal match time by adding one year to the
     * current value.
     */
    void addMatchYear();

    /**
     * @brief Increments the match time by one day of the week.
     *
     * This function updates the internal match time by adding one day to the
     * current day of the week.
     */
    void addMatchDayOfWeek();

    /**
     * @brief Decrements the match time by one second.
     *
     * This function updates the internal match time by subtracting one second
     * from the current second.
     */
    void removeMatchSecond();

    /**
     * @brief Decrements the match time by one minute.
     *
     * This function updates the internal match time by subtracting one minute
     * from the current minute.
     */
    void removeMatchMinute();

    /**
     * @brief Decrements the match time by one hour.
     *
     * This function updates the internal match time by subtracting one hour
     * from the current hour.
     */
    void removeMatchHour();

    /**
     * @brief Decrements the match time by one day.
     *
     * This function updates the internal match time by subtracting one day
     * from the current day.
     */
    void removeMatchDay();

    /**
     * @brief Decrements the match time by one month.
     *
     * This function updates the internal match time by subtracting one month
     * from the current month.
     */
    void removeMatchMonth();

    /**
     * @brief Decrements the match time by one year.
     *
     * This function updates the internal match time by subtracting one year
     * from the current year.
     */
    void removeMatchYear();

    /**
     * @brief Removes the match criteria for the day of the week.
     *
     * This function updates the internal match time by removing the day of the week
     * from the matching criteria.
     */
    void removeMatchDayOfWeek();

    /**
     * @brief Checks if the current second matches the set criteria.
     *
     * This function compares the current second with the set match criteria (if any)
     * and returns true if there is a match, false otherwise.
     *
     * @return `True` if the current second matches the criteria, `false` otherwise.
     */
    bool isMatchingSecond();

    /**
     * @brief Checks if the current minute matches the set criteria.
     *
     * This function compares the current minute with the set match criteria (if any)
     * and returns `true` if there is a match, `false` otherwise.
     *
     * @return `True` if the current minute matches the criteria, `false` otherwise.
     */
    bool isMatchingMinute();

    /**
     * @brief Checks if the current hour matches the set criteria.
     *
     * This function compares the current hour with the set match criteria (if any)
     * and returns `true` if there is a match, `false` otherwise.
     *
     * @return `True` if the current hour matches the criteria, `false` otherwise.
     */
    bool isMatchingHour();

    /**
     * @brief Checks if the current day matches the set criteria.
     *
     * This function compares the current day with the set match criteria (if any)
     * and returns `true` if there is a match, `false` otherwise.
     *
     * @return `True` if the current day matches the criteria, `false` otherwise.
     */
    bool isMatchingDay();

    /**
     * @brief Checks if the current month matches the set criteria.
     *
     * This function compares the current month with the set match criteria (if any)
     * and returns `true` if there is a match, `false` otherwise.
     *
     * @return `True` if the current month matches the criteria, `false` otherwise.
     */
    bool isMatchingMonth();

    /**
     * @brief Checks if the current year matches the set criteria.
     *
     * This function compares the current year with the set match criteria (if any)
     * and returns `true` if there is a match, `false` otherwise.
     *
     * @return `True` if the current year matches the criteria, `false` otherwise.
     */
    bool isMatchingYear();

    /**
     * @brief Checks if the current day of the week matches the set criteria.
     *
     * This function compares the current day of the week with the set match criteria
     * (if any) and returns `true` if there is a match, `false` otherwise.
     *
     * @return `True` if the current day of the week matches the criteria, `false` otherwise.
     */
    bool isMatchingDayOfWeek();
};

/**
 * @brief Class for interfacing with a real-time clock (RTC).
 *
 * The RTClock class provides functionality to get and set the time, date, and other time-related
 * operations, such as day of the week, alarm management, and more.
 */
class RTClock
{
private:
    bool is_initialized;

public:
    /**
     * @brief Constructor to initialize the real-time clock (RTC).
     */
    RTClock();

    /**
     * @brief Destructor for the real-time clock (RTC).
     */
    ~RTClock();

    /**
     * @brief Initializes the real-time clock (RTC).
     *
     * @return `True` if the initialization was successful, `false` otherwise.
     */
    bool begin();

    /**
     * @brief Retrieves the current time from the real-time clock (RTC).
     *
     * This function retrieves the current time from the RTC and stores it in the provided
     * RTCTime object. The RTCTime object will be updated with the latest time and date
     * information from the RTC module.
     *
     * @param `t` A reference to an RTCTime object where the current time will be stored.
     *
     * @return `True` if the time was successfully retrieved and stored in the RTCTime object,
     * `false` if there was an error during the operation.
     */
    bool getTime(RTCTime &t);

    /**
     * @brief Sets a periodic callback function triggered by the real-time clock (RTC).
     *
     * This function configures a callback function to be executed at a specific periodic interval,
     * as defined by the `Period` parameter. The callback function will be invoked automatically
     * by the RTC at the specified rate.
     *
     * @param `fnc` The callback function to be executed periodically. The function must match
     * the `rtc_cbk_t` type signature.
     * @param `p` The period at which the callback function should be triggered. This is specified
     * as a value from the `Period` enumeration.
     *
     * @return `True` if the callback was successfully set, `false` otherwise.
     */
    bool setPeriodicCallback(rtc_cbk_t fnc, Period p);

    /**
     * @brief Sets an alarm callback function triggered when the specified conditions are met.
     *
     * This function configures a callback function to be executed when the real-time clock (RTC)
     * matches the specified date and time conditions defined in the `RTCTime` and `AlarmMatch` parameters.
     *
     * @param `fnc` The callback function to be executed when the alarm triggers. The function must
     * match the `rtc_cbk_t` type signature.
     * @param `t` The target time for the alarm, specified as an RTCTime object.
     * @param `m` The alarm match conditions, specified using the AlarmMatch object. This determines
     * which components of the RTCTime must match (e.g., year, month, day).
     *
     * @return `True` if the alarm callback was successfully set, `false` otherwise.
     */
    bool setAlarmCallback(rtc_cbk_t fnc, RTCTime &t, AlarmMatch &m);

    /**
     * @brief Configures an alarm based on the specified time and matching criteria.
     *
     * This function sets an alarm on the real-time clock (RTC). The alarm will be triggered
     * when the RTC's current time matches the conditions specified by the `RTCTime` and
     * `AlarmMatch` parameters.
     *
     * @param `t` The target time for the alarm, specified as an RTCTime object.
     * @param `m` The alarm match conditions, specified using the AlarmMatch object. This determines
     * which components of the RTCTime must match.
     *
     * @return `True` if the alarm was successfully set, `false` otherwise.
     */
    bool setAlarm(RTCTime &t, AlarmMatch &m);

    /**
     * @brief Checks if the RTC (Real-Time Clock) is currently running.
     *
     * This function verifies whether the RTC module is operational and maintaining time.
     *
     * @return `True` if the RTC is running, `false` otherwise.
     */
    bool isRunning();

    /**
     * @brief Sets the current time of the RTC (Real-Time Clock).
     *
     * This function updates the RTC with the provided time.
     *
     * @param `t` A reference to an RTCTime object containing the desired time to set.
     *
     * @return `True` if the time was successfully updated, `false` otherwise.
     */
    bool setTime(RTCTime &t);

    /**
     * @brief Sets the RTC time only if the clock is not currently running.
     *
     * This function checks if the RTC is stopped and updates its time with the provided
     * RTCTime object if the clock is not running.
     *
     * @param `t` A reference to an RTCTime object containing the desired time to set.
     *
     * @return `True` if the time was successfully updated, `false` otherwise.
     */
    bool setTimeIfNotRunning(RTCTime &t);
};

extern RTClock RTC;

#endif
