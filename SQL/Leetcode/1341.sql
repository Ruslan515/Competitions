-- https://leetcode.com/problems/movie-rating/
# Write your MySQL query statement below
with t1 as (
    select
        user_id,
        count(*) as cnt
    from MovieRating
    group by user_id
),
    t2 as (
        select
            max(cnt)
        from t1
    ),
    t3 as (
        select
            *
        from t1
        where cnt = (
            select
                *
            from t2
            )
    ),
    ans_user as (
        select
            u.name as results
        from t3 join  Users u on t3.user_id = u.user_id
        order by u.name
        limit 1
    ),
    t5 as (
        select
            movie_id,
            avg(rating) avg_rating
        from MovieRating
        where year(created_at) = 2020 and month(created_at) = 02
        group by movie_id
    ),
    t6 as (
        select
            max(avg_rating)
        from t5
    ),
    t7 as (
        select
            *
        from t5
        where avg_rating = (
            select
                *
            from t6
            )
    ),
    ans_movie as (
        select
            title as results
        from t7 join Movies m on t7.movie_id = m.movie_id
        order by title
        limit 1
    ),
    ans as (
        select
            *
        from ans_user
        union all
        select
            *
        from ans_movie
    )


select
    *
from ans
