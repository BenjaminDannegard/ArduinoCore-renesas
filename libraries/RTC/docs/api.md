# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class` [`AlarmMatch`](#class_alarm_match) | Class representing the alarm match system.
`class` [`RTClock`](#class_r_t_clock) | Class for interfacing with a real-time clock (RTC).
`class` [`RTCTime`](#class_r_t_c_time) | A class representing time in the context of an RTC (Real-Time Clock).
`struct` [`timeval`](#structtimeval) | 

# class `AlarmMatch` <a id="class_alarm_match" class="anchor"></a>

Class representing the alarm match system.

This class is used to define how an alarm matches a set of conditions or criteria to trigger an action, such as a timer or event.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`AlarmMatch`](#class_alarm_match_1a2d54ef9ddc542da32fe103b4e7ab28b3) | Default constructor for the [AlarmMatch](#class_alarm_match) class. |
| [`~AlarmMatch`](#class_alarm_match_1a5afd0d3d3f96c641ecbd3450ca775863) | Destructor for the [AlarmMatch](#class_alarm_match) class. |
| [`addMatchSecond`](#class_alarm_match_1aecccdfaf4a13b856ea39b3563c0047c9) | Increments the match time by one second. |
| [`addMatchMinute`](#class_alarm_match_1aa6c7ff0591e656dde418b47221b03f98) | Increments the match time by one minute. |
| [`addMatchHour`](#class_alarm_match_1aaaa7278c42a02c157f19d7adf630efeb) | Increments the match time by one hour. |
| [`addMatchDay`](#class_alarm_match_1a7750e8bd7fa3d9e8aba05d18549f9e4a) | Increments the match time by one day. |
| [`addMatchMonth`](#class_alarm_match_1a535672e2cf4435a2ef3c194359995813) | Increments the match time by one month. |
| [`addMatchYear`](#class_alarm_match_1a29be33fca9a0993be0e0c53b1f056a89) | Increments the match time by one year. |
| [`addMatchDayOfWeek`](#class_alarm_match_1a2c824482a6096fb8d7d156558dfa017b) | Increments the match time by one day of the week. |
| [`removeMatchSecond`](#class_alarm_match_1a2acb110c3cf78858addfd47b973d384b) | Decrements the match time by one second. |
| [`removeMatchMinute`](#class_alarm_match_1ad07250d87328a2fb737af1aae77cbf6b) | Decrements the match time by one minute. |
| [`removeMatchHour`](#class_alarm_match_1ad2d0f7580893e3fa816f557d48b14dde) | Decrements the match time by one hour. |
| [`removeMatchDay`](#class_alarm_match_1af5fd4dadc4adcae8ede004f66eaa12f6) | Decrements the match time by one day. |
| [`removeMatchMonth`](#class_alarm_match_1a37b940e78e62fc2d3e508b192be2eb68) | Decrements the match time by one month. |
| [`removeMatchYear`](#class_alarm_match_1ac90e5a925727f34b659a41f0c3a4d426) | Decrements the match time by one year. |
| [`removeMatchDayOfWeek`](#class_alarm_match_1ae681f0ee94875bc410a92327dd204b03) | Removes the match criteria for the day of the week. |
| [`isMatchingSecond`](#class_alarm_match_1a52de136a3d64383fb758eea86fcf3946) | Checks if the current second matches the set criteria. |
| [`isMatchingMinute`](#class_alarm_match_1ad4d0dfe998cd89c9a9682737a7aee338) | Checks if the current minute matches the set criteria. |
| [`isMatchingHour`](#class_alarm_match_1a73eab2cb02cd8bb12479022cc52ce54f) | Checks if the current hour matches the set criteria. |
| [`isMatchingDay`](#class_alarm_match_1a9f26a4bdc6febad854218bf9c142651e) | Checks if the current day matches the set criteria. |
| [`isMatchingMonth`](#class_alarm_match_1a536093cce64b2e1c4a351815e1313193) | Checks if the current month matches the set criteria. |
| [`isMatchingYear`](#class_alarm_match_1a0b8748eecf57c8c7f2dffcfba944407e) | Checks if the current year matches the set criteria. |
| [`isMatchingDayOfWeek`](#class_alarm_match_1ac8c8ab1655f28c78c5ec648beeb52ba0) | Checks if the current day of the week matches the set criteria. |

## Members

### `AlarmMatch` <a id="class_alarm_match_1a2d54ef9ddc542da32fe103b4e7ab28b3" class="anchor"></a>

```cpp
AlarmMatch()
```

Default constructor for the [AlarmMatch](#class_alarm_match) class.

<hr />

### `~AlarmMatch` <a id="class_alarm_match_1a5afd0d3d3f96c641ecbd3450ca775863" class="anchor"></a>

```cpp
~AlarmMatch()
```

Destructor for the [AlarmMatch](#class_alarm_match) class.

<hr />

### `addMatchSecond` <a id="class_alarm_match_1aecccdfaf4a13b856ea39b3563c0047c9" class="anchor"></a>

```cpp
void addMatchSecond()
```

Increments the match time by one second.

This function updates the internal match time by adding one second to the current value.
<hr />

### `addMatchMinute` <a id="class_alarm_match_1aa6c7ff0591e656dde418b47221b03f98" class="anchor"></a>

```cpp
void addMatchMinute()
```

Increments the match time by one minute.

This function updates the internal match time by adding one minute to the current value.
<hr />

### `addMatchHour` <a id="class_alarm_match_1aaaa7278c42a02c157f19d7adf630efeb" class="anchor"></a>

```cpp
void addMatchHour()
```

Increments the match time by one hour.

This function updates the internal match time by adding one hour to the current value.
<hr />

### `addMatchDay` <a id="class_alarm_match_1a7750e8bd7fa3d9e8aba05d18549f9e4a" class="anchor"></a>

```cpp
void addMatchDay()
```

Increments the match time by one day.

This function updates the internal match time by adding one day to the current value.
<hr />

### `addMatchMonth` <a id="class_alarm_match_1a535672e2cf4435a2ef3c194359995813" class="anchor"></a>

```cpp
void addMatchMonth()
```

Increments the match time by one month.

This function updates the internal match time by adding one month to the current value.
<hr />

### `addMatchYear` <a id="class_alarm_match_1a29be33fca9a0993be0e0c53b1f056a89" class="anchor"></a>

```cpp
void addMatchYear()
```

Increments the match time by one year.

This function updates the internal match time by adding one year to the current value.
<hr />

### `addMatchDayOfWeek` <a id="class_alarm_match_1a2c824482a6096fb8d7d156558dfa017b" class="anchor"></a>

```cpp
void addMatchDayOfWeek()
```

Increments the match time by one day of the week.

This function updates the internal match time by adding one day to the current day of the week.
<hr />

### `removeMatchSecond` <a id="class_alarm_match_1a2acb110c3cf78858addfd47b973d384b" class="anchor"></a>

```cpp
void removeMatchSecond()
```

Decrements the match time by one second.

This function updates the internal match time by subtracting one second from the current second.
<hr />

### `removeMatchMinute` <a id="class_alarm_match_1ad07250d87328a2fb737af1aae77cbf6b" class="anchor"></a>

```cpp
void removeMatchMinute()
```

Decrements the match time by one minute.

This function updates the internal match time by subtracting one minute from the current minute.
<hr />

### `removeMatchHour` <a id="class_alarm_match_1ad2d0f7580893e3fa816f557d48b14dde" class="anchor"></a>

```cpp
void removeMatchHour()
```

Decrements the match time by one hour.

This function updates the internal match time by subtracting one hour from the current hour.
<hr />

### `removeMatchDay` <a id="class_alarm_match_1af5fd4dadc4adcae8ede004f66eaa12f6" class="anchor"></a>

```cpp
void removeMatchDay()
```

Decrements the match time by one day.

This function updates the internal match time by subtracting one day from the current day.
<hr />

### `removeMatchMonth` <a id="class_alarm_match_1a37b940e78e62fc2d3e508b192be2eb68" class="anchor"></a>

```cpp
void removeMatchMonth()
```

Decrements the match time by one month.

This function updates the internal match time by subtracting one month from the current month.
<hr />

### `removeMatchYear` <a id="class_alarm_match_1ac90e5a925727f34b659a41f0c3a4d426" class="anchor"></a>

```cpp
void removeMatchYear()
```

Decrements the match time by one year.

This function updates the internal match time by subtracting one year from the current year.
<hr />

### `removeMatchDayOfWeek` <a id="class_alarm_match_1ae681f0ee94875bc410a92327dd204b03" class="anchor"></a>

```cpp
void removeMatchDayOfWeek()
```

Removes the match criteria for the day of the week.

This function updates the internal match time by removing the day of the week from the matching criteria.
<hr />

### `isMatchingSecond` <a id="class_alarm_match_1a52de136a3d64383fb758eea86fcf3946" class="anchor"></a>

```cpp
bool isMatchingSecond()
```

Checks if the current second matches the set criteria.

This function compares the current second with the set match criteria (if any) and returns true if there is a match, false otherwise.

#### Returns
`True` if the current second matches the criteria, `false` otherwise.
<hr />

### `isMatchingMinute` <a id="class_alarm_match_1ad4d0dfe998cd89c9a9682737a7aee338" class="anchor"></a>

```cpp
bool isMatchingMinute()
```

Checks if the current minute matches the set criteria.

This function compares the current minute with the set match criteria (if any) and returns `true` if there is a match, `false` otherwise.

#### Returns
`True` if the current minute matches the criteria, `false` otherwise.
<hr />

### `isMatchingHour` <a id="class_alarm_match_1a73eab2cb02cd8bb12479022cc52ce54f" class="anchor"></a>

```cpp
bool isMatchingHour()
```

Checks if the current hour matches the set criteria.

This function compares the current hour with the set match criteria (if any) and returns `true` if there is a match, `false` otherwise.

#### Returns
`True` if the current hour matches the criteria, `false` otherwise.
<hr />

### `isMatchingDay` <a id="class_alarm_match_1a9f26a4bdc6febad854218bf9c142651e" class="anchor"></a>

```cpp
bool isMatchingDay()
```

Checks if the current day matches the set criteria.

This function compares the current day with the set match criteria (if any) and returns `true` if there is a match, `false` otherwise.

#### Returns
`True` if the current day matches the criteria, `false` otherwise.
<hr />

### `isMatchingMonth` <a id="class_alarm_match_1a536093cce64b2e1c4a351815e1313193" class="anchor"></a>

```cpp
bool isMatchingMonth()
```

Checks if the current month matches the set criteria.

This function compares the current month with the set match criteria (if any) and returns `true` if there is a match, `false` otherwise.

#### Returns
`True` if the current month matches the criteria, `false` otherwise.
<hr />

### `isMatchingYear` <a id="class_alarm_match_1a0b8748eecf57c8c7f2dffcfba944407e" class="anchor"></a>

```cpp
bool isMatchingYear()
```

Checks if the current year matches the set criteria.

This function compares the current year with the set match criteria (if any) and returns `true` if there is a match, `false` otherwise.

#### Returns
`True` if the current year matches the criteria, `false` otherwise.
<hr />

### `isMatchingDayOfWeek` <a id="class_alarm_match_1ac8c8ab1655f28c78c5ec648beeb52ba0" class="anchor"></a>

```cpp
bool isMatchingDayOfWeek()
```

Checks if the current day of the week matches the set criteria.

This function compares the current day of the week with the set match criteria (if any) and returns `true` if there is a match, `false` otherwise.

#### Returns
`True` if the current day of the week matches the criteria, `false` otherwise.
<hr />

# class `RTClock` <a id="class_r_t_clock" class="anchor"></a>

Class for interfacing with a real-time clock (RTC).

The [RTClock](#class_r_t_clock) class provides functionality to get and set the time, date, and other time-related operations, such as day of the week, alarm management, and more.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`RTClock`](#class_r_t_clock_1a1fefceddd93d040e3f4296c573e0fe34) | Constructor to initialize the real-time clock (RTC). |
| [`~RTClock`](#class_r_t_clock_1a8e569b9095a0a7545278ebf132564492) | Destructor for the real-time clock (RTC). |
| [`begin`](#class_r_t_clock_1ad753f953539b7ec0e56a9f15c358c2c5) | Initializes the real-time clock (RTC). |
| [`getTime`](#class_r_t_clock_1a4c335640f3f62f42dd5ed3fad314e3e7) | Retrieves the current time from the real-time clock (RTC). |
| [`setPeriodicCallback`](#class_r_t_clock_1a47258e8554ded2f597fdb4f6e6c77548) | Sets a periodic callback function triggered by the real-time clock (RTC). |
| [`setAlarmCallback`](#class_r_t_clock_1a7e24b8f5727297ab4974a40fb506d961) | Sets an alarm callback function triggered when the specified conditions are met. |
| [`setAlarm`](#class_r_t_clock_1a04ef8ba0c3ce454ea3b7868f582fae48) | Configures an alarm based on the specified time and matching criteria. |
| [`isRunning`](#class_r_t_clock_1a09d0a22117e98e449dee1d5a74649eb5) | Checks if the RTC (Real-Time Clock) is currently running. |
| [`setTime`](#class_r_t_clock_1a64b98ad69891a6e9b1b85b27f4df7ca3) | Sets the current time of the RTC (Real-Time Clock). |
| [`setTimeIfNotRunning`](#class_r_t_clock_1a4168c5950e860aa7ff1af7b24fed2a94) | Sets the RTC time only if the clock is not currently running. |

## Members

### `RTClock` <a id="class_r_t_clock_1a1fefceddd93d040e3f4296c573e0fe34" class="anchor"></a>

```cpp
RTClock()
```

Constructor to initialize the real-time clock (RTC).

<hr />

### `~RTClock` <a id="class_r_t_clock_1a8e569b9095a0a7545278ebf132564492" class="anchor"></a>

```cpp
~RTClock()
```

Destructor for the real-time clock (RTC).

<hr />

### `begin` <a id="class_r_t_clock_1ad753f953539b7ec0e56a9f15c358c2c5" class="anchor"></a>

```cpp
bool begin()
```

Initializes the real-time clock (RTC).

#### Returns
`True` if the initialization was successful, `false` otherwise.
<hr />

### `getTime` <a id="class_r_t_clock_1a4c335640f3f62f42dd5ed3fad314e3e7" class="anchor"></a>

```cpp
bool getTime( RTCTime & t)
```

Retrieves the current time from the real-time clock (RTC).

This function retrieves the current time from the RTC and stores it in the provided [RTCTime](#class_r_t_c_time) object. The [RTCTime](#class_r_t_c_time) object will be updated with the latest time and date information from the RTC module.

#### Parameters
* `t` A reference to an [RTCTime](#class_r_t_c_time) object where the current time will be stored.

#### Returns
`True` if the time was successfully retrieved and stored in the [RTCTime](#class_r_t_c_time) object, `false` if there was an error during the operation.
<hr />

### `setPeriodicCallback` <a id="class_r_t_clock_1a47258e8554ded2f597fdb4f6e6c77548" class="anchor"></a>

```cpp
bool setPeriodicCallback(rtc_cbk_t fnc, Period p)
```

Sets a periodic callback function triggered by the real-time clock (RTC).

This function configures a callback function to be executed at a specific periodic interval, as defined by the `Period` parameter. The callback function will be invoked automatically by the RTC at the specified rate.

#### Parameters
* `fnc` The callback function to be executed periodically. The function must match the `rtc_cbk_t` type signature. 

* `p` The period at which the callback function should be triggered. This is specified as a value from the `Period` enumeration.

#### Returns
`True` if the callback was successfully set, `false` otherwise.
<hr />

### `setAlarmCallback` <a id="class_r_t_clock_1a7e24b8f5727297ab4974a40fb506d961" class="anchor"></a>

```cpp
bool setAlarmCallback(rtc_cbk_t fnc, RTCTime & t, AlarmMatch & m)
```

Sets an alarm callback function triggered when the specified conditions are met.

This function configures a callback function to be executed when the real-time clock (RTC) matches the specified date and time conditions defined in the [RTCTime](#class_r_t_c_time) and [AlarmMatch](#class_alarm_match) parameters.

#### Parameters
* `fnc` The callback function to be executed when the alarm triggers. The function must match the `rtc_cbk_t` type signature. 

* `t` The target time for the alarm, specified as an [RTCTime](#class_r_t_c_time) object. 

* `m` The alarm match conditions, specified using the [AlarmMatch](#class_alarm_match) object. This determines which components of the [RTCTime](#class_r_t_c_time) must match (e.g., year, month, day).

#### Returns
`True` if the alarm callback was successfully set, `false` otherwise.
<hr />

### `setAlarm` <a id="class_r_t_clock_1a04ef8ba0c3ce454ea3b7868f582fae48" class="anchor"></a>

```cpp
bool setAlarm( RTCTime & t, AlarmMatch & m)
```

Configures an alarm based on the specified time and matching criteria.

This function sets an alarm on the real-time clock (RTC). The alarm will be triggered when the RTC's current time matches the conditions specified by the [RTCTime](#class_r_t_c_time) and [AlarmMatch](#class_alarm_match) parameters.

#### Parameters
* `t` The target time for the alarm, specified as an [RTCTime](#class_r_t_c_time) object. 

* `m` The alarm match conditions, specified using the [AlarmMatch](#class_alarm_match) object. This determines which components of the [RTCTime](#class_r_t_c_time) must match.

#### Returns
`True` if the alarm was successfully set, `false` otherwise.
<hr />

### `isRunning` <a id="class_r_t_clock_1a09d0a22117e98e449dee1d5a74649eb5" class="anchor"></a>

```cpp
bool isRunning()
```

Checks if the RTC (Real-Time Clock) is currently running.

This function verifies whether the RTC module is operational and maintaining time.

#### Returns
`True` if the RTC is running, `false` otherwise.
<hr />

### `setTime` <a id="class_r_t_clock_1a64b98ad69891a6e9b1b85b27f4df7ca3" class="anchor"></a>

```cpp
bool setTime( RTCTime & t)
```

Sets the current time of the RTC (Real-Time Clock).

This function updates the RTC with the provided time.

#### Parameters
* `t` A reference to an [RTCTime](#class_r_t_c_time) object containing the desired time to set.

#### Returns
`True` if the time was successfully updated, `false` otherwise.
<hr />

### `setTimeIfNotRunning` <a id="class_r_t_clock_1a4168c5950e860aa7ff1af7b24fed2a94" class="anchor"></a>

```cpp
bool setTimeIfNotRunning( RTCTime & t)
```

Sets the RTC time only if the clock is not currently running.

This function checks if the RTC is stopped and updates its time with the provided [RTCTime](#class_r_t_c_time) object if the clock is not running.

#### Parameters
* `t` A reference to an [RTCTime](#class_r_t_c_time) object containing the desired time to set.

#### Returns
`True` if the time was successfully updated, `false` otherwise.
<hr />

# class `RTCTime` <a id="class_r_t_c_time" class="anchor"></a>

A class representing time in the context of an RTC (Real-Time Clock).

The [RTCTime](#class_r_t_c_time) class encapsulates time-related information and provides utility methods to interact with and manipulate RTC time.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`RTCTime`](#class_r_t_c_time_1a924ea08fcfda4cd7bba69d27e6044d8c) | Default constructor for the [RTCTime](#class_r_t_c_time) class. |
| [`RTCTime`](#class_r_t_c_time_1a1845bc8c5cc390e771a8569961821681) | Constructor for the [RTCTime](#class_r_t_c_time) class with a given time. |
| [`RTCTime`](#class_r_t_c_time_1adce8b95b38afbd4c83c95a55ef3199c9) | Constructor for the [RTCTime](#class_r_t_c_time) class with a given `tm` structure. |
| [`RTCTime`](#class_r_t_c_time_1af650d794e8dc4b68e2f7edf8904290c8) | Constructor for the [RTCTime](#class_r_t_c_time) class with specific date and time parameters. |
| [`~RTCTime`](#class_r_t_c_time_1ab8bee04da843e1f4d573b8dc8456045c) | Destructor for the [RTCTime](#class_r_t_c_time) class. |
| [`setDayOfMonth`](#class_r_t_c_time_1af9abac029cfc446635d0418cb026cb05) | Sets the day of the month. |
| [`setMonthOfYear`](#class_r_t_c_time_1ae9b91fdd5ac696f476bca77ab00d3924) | Sets the month of the year. |
| [`setYear`](#class_r_t_c_time_1a03f3a280099446d866dd410c6c0e37ea) | Sets the year. |
| [`setHour`](#class_r_t_c_time_1a314592b177aa3647f52b151b397c615c) | Sets the hour of the day. |
| [`setMinute`](#class_r_t_c_time_1afaa2c25a40be5ad217147fac3b59156a) | Sets the minute of the hour. |
| [`setSecond`](#class_r_t_c_time_1a00b5a03046370aa1d1895863a9a17464) | Sets the second of the minute. |
| [`setDayOfWeek`](#class_r_t_c_time_1aea6e5bd41959cb1eaf4cf3ba81f4f27f) | Sets the day of the week. |
| [`setSaveLight`](#class_r_t_c_time_1a46667e749264e0487193495e9f84b740) | Sets whether daylight saving time is active. |
| [`setUnixTime`](#class_r_t_c_time_1a8d50fa1ee9a132a037500f39845bdabb) | Sets the time using a Unix timestamp. |
| [`setTM`](#class_r_t_c_time_1a8a63142d7699025c78cbbf252b9dbe62) | Sets the time from a struct tm. |
| [`getDayOfMonth`](#class_r_t_c_time_1a42bfdfc2ae6d2cf81ddc0a6f5814f65a) | Gets the day of the month. |
| [`getMonth`](#class_r_t_c_time_1a43aed822be5e9e26efce91050de7aca8) | Gets the month of the year. |
| [`getYear`](#class_r_t_c_time_1ab7ad8a017d1972c4a80f3c63e6140f80) | Gets the year. |
| [`getHour`](#class_r_t_c_time_1a226aec3347c7d2406162af6ddf35ebf6) | Gets the hour of the day. |
| [`getMinutes`](#class_r_t_c_time_1a4569498a7960c995e266b7d23eac98ba) | Gets the minutes of the hour. |
| [`getSeconds`](#class_r_t_c_time_1a86e8e5984d1c0d954836f25d010c9f46) | Gets the seconds of the minute. |
| [`getDayOfWeek`](#class_r_t_c_time_1a72f06ebb1c1368134f6616bc905ca526) | Gets the day of the week. |
| [`getUnixTime`](#class_r_t_c_time_1a7215c300c30e6423c62cac39443871bd) | Gets the Unix timestamp. |
| [`getTmTime`](#class_r_t_c_time_1a7830e079cff08391ef28899e910e79bd) | Gets the time as a struct `tm`. |
| [`toString`](#class_r_t_c_time_1afc343321d5caee657655f7c7d998f4c0) | Returns the ISO 8601 string representation of the date and time. |
| [`operator arduino::String`](#class_r_t_c_time_1a03bf4e2ba6aaab9e829be5b17be55f36) | Returns the ISO 8601 string representation of the date and time by calling the [toString()](#class_r_t_c_time_1afc343321d5caee657655f7c7d998f4c0) method. |

## Members

### `RTCTime` <a id="class_r_t_c_time_1a924ea08fcfda4cd7bba69d27e6044d8c" class="anchor"></a>

```cpp
RTCTime()
```

Default constructor for the [RTCTime](#class_r_t_c_time) class.

<hr />

### `RTCTime` <a id="class_r_t_c_time_1a1845bc8c5cc390e771a8569961821681" class="anchor"></a>

```cpp
RTCTime(time_t t)
```

Constructor for the [RTCTime](#class_r_t_c_time) class with a given time.

Initializes the [RTCTime](#class_r_t_c_time) object with the specified time.

#### Parameters
* `t` A time_t value representing the time to initialize the [RTCTime](#class_r_t_c_time) object with.
<hr />

### `RTCTime` <a id="class_r_t_c_time_1adce8b95b38afbd4c83c95a55ef3199c9" class="anchor"></a>

```cpp
RTCTime(struct tm & t)
```

Constructor for the [RTCTime](#class_r_t_c_time) class with a given `tm` structure.

#### Parameters
* `t` A reference to a struct `tm` that contains the broken-down time to initialize the [RTCTime](#class_r_t_c_time) object with.
<hr />

### `RTCTime` <a id="class_r_t_c_time_1af650d794e8dc4b68e2f7edf8904290c8" class="anchor"></a>

```cpp
RTCTime(int _day, Month _m, int _year, int _hours, int _minutes, int _seconds, DayOfWeek _dof, SaveLight _sl)
```

Constructor for the [RTCTime](#class_r_t_c_time) class with specific date and time parameters.

Initializes the [RTCTime](#class_r_t_c_time) object with the specified date, time, day of the week, and daylight saving time status.

#### Parameters
* `_day` The day of the month. 

* `_m` The month of the year (using the Month enum, e.g., JANUARY, FEBRUARY, etc.). 

* `_year` The year (e.g., 2024). 

* `_hours` The hour of the day (0-23). 

* `_minutes` The minute of the hour (0-59). 

* `_seconds` The second of the minute (0-59). 

* `_dof` The day of the week (using the DayOfWeek enum, e.g., MONDAY, TUESDAY, etc.). 

* `_sl` The daylight saving time status (using the SaveLight enum, e.g., DST_ON, DST_OFF).
<hr />

### `~RTCTime` <a id="class_r_t_c_time_1ab8bee04da843e1f4d573b8dc8456045c" class="anchor"></a>

```cpp
~RTCTime()
```

Destructor for the [RTCTime](#class_r_t_c_time) class.

<hr />

### `setDayOfMonth` <a id="class_r_t_c_time_1af9abac029cfc446635d0418cb026cb05" class="anchor"></a>

```cpp
bool setDayOfMonth(int day)
```

Sets the day of the month.

#### Parameters
* `day` The day of the month.

#### Returns
`true` if the day is set successfully, `false` if the day is out of range.
<hr />

### `setMonthOfYear` <a id="class_r_t_c_time_1ae9b91fdd5ac696f476bca77ab00d3924" class="anchor"></a>

```cpp
bool setMonthOfYear(Month m)
```

Sets the month of the year.

#### Parameters
* `m` The month.

#### Returns
`true` if the month is set successfully, `false` if the month is out of range.
<hr />

### `setYear` <a id="class_r_t_c_time_1a03f3a280099446d866dd410c6c0e37ea" class="anchor"></a>

```cpp
bool setYear(int year)
```

Sets the year.

#### Parameters
* `year` The year (e.g., 1989 or 2022).

#### Returns
`true` if the year is set successfully, `false` if the year is invalid.
<hr />

### `setHour` <a id="class_r_t_c_time_1a314592b177aa3647f52b151b397c615c" class="anchor"></a>

```cpp
bool setHour(int hour)
```

Sets the hour of the day.

#### Parameters
* `hour` The hour.

#### Returns
`true` if the hour is set successfully, `false` if the hour is out of range.
<hr />

### `setMinute` <a id="class_r_t_c_time_1afaa2c25a40be5ad217147fac3b59156a" class="anchor"></a>

```cpp
bool setMinute(int minute)
```

Sets the minute of the hour.

#### Parameters
* `minute` The minute.

#### Returns
`true` if the minute is set successfully, `false` if the minute is out of range.
<hr />

### `setSecond` <a id="class_r_t_c_time_1a00b5a03046370aa1d1895863a9a17464" class="anchor"></a>

```cpp
bool setSecond(int second)
```

Sets the second of the minute.

#### Parameters
* `second` The second.

#### Returns
`true` if the second is set successfully, `false` if the second is out of range.
<hr />

### `setDayOfWeek` <a id="class_r_t_c_time_1aea6e5bd41959cb1eaf4cf3ba81f4f27f" class="anchor"></a>

```cpp
bool setDayOfWeek(DayOfWeek d)
```

Sets the day of the week.

#### Parameters
* `d` The day of the week (from the DayOfWeek enumeration).

#### Returns
`true` if the day of the week is set successfully, `false` if the value is invalid.
<hr />

### `setSaveLight` <a id="class_r_t_c_time_1a46667e749264e0487193495e9f84b740" class="anchor"></a>

```cpp
bool setSaveLight(SaveLight sl)
```

Sets whether daylight saving time is active.

#### Parameters
* `sl` The SaveLight enumeration value.

#### Returns
`true` if the daylight saving time setting is applied successfully, `false` otherwise.
<hr />

### `setUnixTime` <a id="class_r_t_c_time_1a8d50fa1ee9a132a037500f39845bdabb" class="anchor"></a>

```cpp
bool setUnixTime(time_t time)
```

Sets the time using a Unix timestamp.

#### Parameters
* `time` The Unix timestamp (seconds since January 1, 1970).

#### Returns
`true` if the Unix timestamp is set successfully, `false` otherwise.
<hr />

### `setTM` <a id="class_r_t_c_time_1a8a63142d7699025c78cbbf252b9dbe62" class="anchor"></a>

```cpp
void setTM(struct tm & t)
```

Sets the time from a struct tm.

#### Parameters
* `t` A reference to a struct tm that contains the time values.
<hr />

### `getDayOfMonth` <a id="class_r_t_c_time_1a42bfdfc2ae6d2cf81ddc0a6f5814f65a" class="anchor"></a>

```cpp
int getDayOfMonth() const
```

Gets the day of the month.

#### Returns
The day of the month.
<hr />

### `getMonth` <a id="class_r_t_c_time_1a43aed822be5e9e26efce91050de7aca8" class="anchor"></a>

```cpp
Month getMonth() const
```

Gets the month of the year.

#### Returns
The month.
<hr />

### `getYear` <a id="class_r_t_c_time_1ab7ad8a017d1972c4a80f3c63e6140f80" class="anchor"></a>

```cpp
int getYear() const
```

Gets the year.

#### Returns
The year.
<hr />

### `getHour` <a id="class_r_t_c_time_1a226aec3347c7d2406162af6ddf35ebf6" class="anchor"></a>

```cpp
int getHour() const
```

Gets the hour of the day.

#### Returns
The hour.
<hr />

### `getMinutes` <a id="class_r_t_c_time_1a4569498a7960c995e266b7d23eac98ba" class="anchor"></a>

```cpp
int getMinutes() const
```

Gets the minutes of the hour.

#### Returns
The minutes.
<hr />

### `getSeconds` <a id="class_r_t_c_time_1a86e8e5984d1c0d954836f25d010c9f46" class="anchor"></a>

```cpp
int getSeconds() const
```

Gets the seconds of the minute.

#### Returns
The seconds.
<hr />

### `getDayOfWeek` <a id="class_r_t_c_time_1a72f06ebb1c1368134f6616bc905ca526" class="anchor"></a>

```cpp
DayOfWeek getDayOfWeek() const
```

Gets the day of the week.

#### Returns
The day of the week.
<hr />

### `getUnixTime` <a id="class_r_t_c_time_1a7215c300c30e6423c62cac39443871bd" class="anchor"></a>

```cpp
time_t getUnixTime()
```

Gets the Unix timestamp.

#### Returns
The Unix timestamp.
<hr />

### `getTmTime` <a id="class_r_t_c_time_1a7830e079cff08391ef28899e910e79bd" class="anchor"></a>

```cpp
struct tm getTmTime()
```

Gets the time as a struct `tm`.

#### Returns
A struct `tm` that contains the time values.
<hr />

### `toString` <a id="class_r_t_c_time_1afc343321d5caee657655f7c7d998f4c0" class="anchor"></a>

```cpp
arduino::String toString() const
```

Returns the ISO 8601 string representation of the date and time.

#### Returns
String The date and time in the format YYYY-MM-DDTHH:MM:SS.
<hr />

### `operator arduino::String` <a id="class_r_t_c_time_1a03bf4e2ba6aaab9e829be5b17be55f36" class="anchor"></a>

```cpp
operator arduino::String() const
```

Returns the ISO 8601 string representation of the date and time by calling the [toString()](#class_r_t_c_time_1afc343321d5caee657655f7c7d998f4c0) method.

#### Returns
String The date and time in the format YYYY-MM-DDTHH:MM:SS.
<hr />

# struct `timeval` <a id="structtimeval" class="anchor"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
| [`tv_sec`](#structtimeval_1aef6ddab1064c430758f9f913b7e4a21e) |  |
| [`tv_usec`](#structtimeval_1a60486501e203aa76351aae5afee09b98) |  |

## Members

### `tv_sec` <a id="structtimeval_1aef6ddab1064c430758f9f913b7e4a21e" class="anchor"></a>

```cpp
time_t tv_sec
```

<hr />

### `tv_usec` <a id="structtimeval_1a60486501e203aa76351aae5afee09b98" class="anchor"></a>

```cpp
useconds_t tv_usec
```

<hr />

