-- https://leetcode.com/problems/weather-type-in-each-country/
# Write your MySQL query statement below
with t1 as (
    select
        country_id,
        avg(weather_state) as avg_w_s
    from Weather
    where day between '2019-11-01' and '2019-11-30'
    group by country_id
),
    t2 as (
        select
            *,
            case
                when avg_w_s <= 15 then 'Cold'
                when avg_w_s >= 25 then 'Hot'
                else 'Warm'
            end as weather_type
        from t1
    )
select
    c.country_name,
    t2.weather_type
from Countries c join t2 on c.country_id = t2.country_id
