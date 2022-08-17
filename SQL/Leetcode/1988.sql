-- https://leetcode.com/problems/find-cutoff-score-for-each-school/
with t1 as (
    select
        s.school_id,
       -- s.capacity,
        coalesce(e.score, -1) as score,
        coalesce(e.student_count, -1) as student_count
    from Schools s left join Exam e on s.capacity >= e.student_count
),
    t2 as (
        select
            *,
            max(student_count) over (partition by school_id) as max_count
        from t1
    ),
    t3 as (
        select
            school_id,
            score,
            min(score) over (partition by school_id) as min_score
        from t2
        where max_count = student_count
    ),
    t4 as (
        select
            school_id,
            score
        from t3 where min_score = score
    )

select
    *
from t4;
