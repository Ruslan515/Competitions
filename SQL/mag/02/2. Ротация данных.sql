create table iimp.src_supp_dmp_forecast
(
    guid_pr               String,
    name_pr               String,
    name_pr_status        String,
    guid_tma              String,
    guid_ws               String,
    guid_art              String,
    date_begin            String,
    date_end              String,
    forecast              String,
    code_contr            String,
    is_in_out             String,
    discount_shelf        String,
    prc_reg_km_total      String,
    type_forecast         String,
    date_create           String,
    date_begin_translated String,
    date_end_translated   String,
    ats                   String,
    filename              String
) engine = ReplacingMergeTree()
order by date_end_translated
partition by toMonth(date_end_translated);



select *
from iimp.src_supp_dmp_forecast
where date_end_translated < now();