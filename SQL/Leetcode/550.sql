-- https://leetcode.com/problems/game-play-analysis-iv/
with t1 as (
    select
        *
    from Activity
    order by player_id, event_date
),
    t2 as (
        select
            player_id,
            min(event_date) as first_date
        from Activity
        group by player_id
    ),
    t3 as (
        select
            *,
            first_date + 1 as next_date
        from t2
    ),
    t4 as (
        select
            count(*) as cnt
        from Activity a join t3 on a.player_id = t3.player_id and a.event_date = t3.next_date
    ),
    t5 as (
        select
            count(distinct player_id) all_cnt
        from Activity
    ),
    ans as (
        select
            round(1.0 * cnt / (
                select
                    *
                from t5
                ), 2) as fraction
        from t4
    )

select
    *
from ans
