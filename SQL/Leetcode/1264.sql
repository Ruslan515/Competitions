-- https://leetcode.com/problems/page-recommendations/
# Write your MySQL query statement below
with t1 as (
    select
        *
    from Friendship
    where user1_id < Friendship.user2_id and user1_id = 1
),
    t2 as (
        select
            user2_id as user1_id,
            user1_id as user2_id
        from Friendship
        where user2_id < Friendship.user1_id and user2_id = 1
    ),
    t3 as (
        select
            *
        from t1
        union all
        select
            *
        from t2
    ),
    t4 as (
        select
            distinct page_id
        from t3 join Likes l on t3.user2_id = l.user_id
    ),
    t5 as (
        select
            page_id
        from Likes
        where user_id = 1
    )
select
    page_id as recommended_page
from t4 where page_id not in (
    select
        *
    from t5
    )
