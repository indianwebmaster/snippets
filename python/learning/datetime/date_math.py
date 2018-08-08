#!/usr/bin/env python
import datetime as dt


class DateMath:
    @staticmethod
    def __get_other_date__(nums_days_offset, format="%d-%b-%Y"):
        other_date = dt.datetime.today() + dt.timedelta(nums_days_offset)
        return other_date.strftime(format)

    @staticmethod
    def get_previous_date(num_days_in_past, format="%d-%b-%Y"):
        return DateMath.__get_other_date__(0 - num_days_in_past, format)

    @staticmethod
    def get_future_date(num_days_in_past, format="%d-%b-%Y"):
        return DateMath.__get_other_date__(num_days_in_past, format)

    @staticmethod
    def convert_str_to_date(date_str, in_format="%m-%d-%Y", out_format="%d-%b-%Y"):
        return dt.datetime.strptime(date_str, in_format).strftime(out_format)


if __name__ == '__main__':
    print(DateMath.convert_str_to_date("10-20-2018"))
    print(DateMath.convert_str_to_date("10202018", "%m%d%Y"))
    print(DateMath.convert_str_to_date("10202018", "%m%d%Y", "%d-%b-%y"))
    print(DateMath.get_previous_date(1))
    print(DateMath.get_future_date(1))
