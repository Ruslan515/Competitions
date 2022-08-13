-- https://leetcode.com/problems/countries-you-can-safely-invest-in/
with t1 as (
    select
        id,
        substring(phone_number, 1, 3) as country_code
    from Person
),
    t2 as (
        select
            id,
            c.name
        from t1 join country c on t1.country_code = c.country_code
    ),
    t3 as (
        select
            c.*,
            t2.name as country_from
        from Calls c join t2 on c.caller_id = t2.id
    ),
    t4 as (
        select
            t3.*,
            t2.name as country_to
        from t3 join t2 on t3.callee_id = t2.id
    ),
    t5 as (
        select
            country_from as country,
            duration
        from t4
        union all
        select
            country_to,
            duration
        from t4
    ),
    t6 as (
        select
            country,
            avg(duration) as avg_dur
        from t5
        group by country
    ),
    t7 as (
        select
            avg(duration)
        from Calls
    )
select
    country
from t6
where avg_dur > (
    select
        *
    from t7
    )
