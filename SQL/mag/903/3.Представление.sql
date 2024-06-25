WITH json_extracted AS (
    SELECT
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'category' :: text AS category,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'compensation_type' :: text AS compensation_type,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'compensation_comment' :: text AS compensation_comment,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'tt_count' :: text AS tt_count,
        COALESCE(
            (
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/common_form' :: text
                ) :: json
            ) ->> 'budget_rub' :: text,
            (
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/common_form' :: text
                ) :: json
            ) ->> 'budget' :: text
        ) AS budget_rub,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'mp_count' :: text AS mp_count,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).stock_dates AS stock_dates,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).supplier_code AS supplier_code,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).supplier_code_kis AS supplier_code_kis,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).supplier_email AS supplier_email,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).supplier_discount AS supplier_discount,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).tp_code AS tp_code,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).tp_name AS tp_name,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).tp_load AS tp_load,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).cost_one_dmp AS cost_one_dmp,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        )."prepackCode" AS prepack_code,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).prepack_discount AS prepack_discount,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).prepack_base_units AS prepack_base_units,
        (scsdata.jdata -> 'status' :: text) ->> 'date' :: text AS is_booked_date,
        (scsdata.jdata -> 'refs' :: text) ->> 'stable_guid' :: text AS scs_stable_guid,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'name' :: text AS name,
        (
            (
                (
                    (
                        (
                            (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                        ) ->> 'data/common_form' :: text
                    ) :: json
                ) -> 'dates' :: text
            ) -> 'from' :: text
        ) :: text AS date_from,
        (
            (
                (
                    (
                        (
                            (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                        ) ->> 'data/common_form' :: text
                    ) :: json
                ) -> 'dates' :: text
            ) -> 'to' :: text
        ) :: text AS date_to,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'pass_cluster_level_1' :: text AS pass_cluster_level_1,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'passClusterLevel1' :: text AS passclusterlevel1,
        (scsdata.jdata -> 'refs' :: text) ->> 'scs_code' :: text AS type,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'recount' :: text AS recalc_type,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'type' :: text AS ptype,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'dmp_type' :: text AS dmp_type,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: jsonb
        ) ->> 'ctype' :: text AS ctype,
        (
            (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
        ) ->> 'data/frmt' :: text AS whs_format,
        (scsdata.jdata -> 'status' :: text) ->> 'bookAP' :: text AS is_booked,
        (scsdata.jdata -> 'status' :: text) ->> 'temporary' :: text AS is_temporary,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'priority' :: text AS priority,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'dmp_after_action' :: text AS dmp_after_action,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'dmp_name' :: text AS dmp_name,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'stock_rotation' :: text AS stock_rotation,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'etalon' :: text AS etalon,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'budget_over_limit' :: text AS budget_over_limit,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'inout' :: text AS "inout",
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: json
        ) ->> 'registered_without_booking' :: text AS registered_without_booking,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: jsonb
        ) ->> 'need_book' :: text AS need_book,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: jsonb
        ) ->> 'ap_exists' :: text AS ap_exists,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: jsonb
        ) ->> 'over_ap' :: text AS over_ap,
        (
            (
                (
                    (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                ) ->> 'data/common_form' :: text
            ) :: jsonb
        ) ->> 'geo_adc' :: text AS geo_adc,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).rc_type AS rc_type,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).action_price AS action_price,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).prepack_regular_price AS prepack_regular_price,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).prepack_dates_from AS prepack_dates_from,
        (
            json_populate_recordset(
                NULL :: scsdata_tp_info,
                (
                    (
                        (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
                    ) ->> 'data/tpFormData' :: text
                ) :: json
            )
        ).prepack_dates_to AS prepack_dates_to,
        (scsdata.jdata -> 'refs' :: text) ->> 'uid' :: text AS user_id,
        scsdata.version,
        scsdata.ats,
        scsdata.uts
    FROM
        scsdata
    WHERE
        scsdata.version >= 0
        AND (
            (
                (scsdata.jdata -> 'data' :: text) -> 'form_data' :: text
            ) ->> 'data/tpFormData' :: text
        ) <> '' :: text
)
SELECT
    DISTINCT ON (
        json_extracted.scs_stable_guid,
        json_extracted.tp_code
    ) json_extracted.scs_stable_guid,
    json_extracted.name,
    CASE
        WHEN json_extracted.type = 'magnit-project' :: text THEN 'udp' :: text
        WHEN json_extracted.type = 'magnit-ukp-modeler' :: text THEN 'ukp' :: text
        ELSE NULL :: text
    END AS type,
    json_extracted.ptype,
    COALESCE(
        json_extracted.pass_cluster_level_1,
        json_extracted.passclusterlevel1
    ) AS cluster,
    json_extracted.date_from :: date AS date_from,
    json_extracted.date_to :: date AS date_to,
    json_extracted.recalc_type,
    json_extracted.dmp_type,
    json_extracted.ctype,
    json_extracted.dmp_after_action,
    json_extracted.dmp_name,
    mp_names.uni_site_name AS mp_name,
    json_extracted.whs_format,
    json_extracted.is_booked,
    json_extracted.is_booked_date,
    json_extracted.is_temporary,
    json_extracted.priority,
    json_extracted.prepack_base_units,
    json_extracted.prepack_code,
    json_extracted.compensation_type,
    json_extracted.prepack_discount,
    json_extracted.tp_code,
    json_extracted.tp_name,
    json_extracted.tp_load,
    json_extracted.compensation_comment,
    json_extracted.mp_count,
    json_extracted.budget_rub,
    json_extracted.tt_count,
    json_extracted.supplier_code,
    regexp_replace(
        json_extracted.supplier_code_kis :: text,
        ' +' :: text,
        '' :: text
    ) :: character varying AS supplier_code_kis,
    json_extracted.supplier_discount,
    json_extracted.supplier_email,
    (
        (json_extracted.stock_dates :: json -> 'from' :: text) :: character varying
    ) :: date AS date_stock_from,
    (
        (json_extracted.stock_dates :: json -> 'to' :: text) :: character varying
    ) :: date AS date_stock_to,
    json_extracted.category,
    json_extracted.cost_one_dmp,
    json_extracted.stock_rotation,
    json_extracted.etalon,
    json_extracted.budget_over_limit,
    json_extracted."inout",
    json_extracted.need_book,
    json_extracted.ap_exists,
    json_extracted.over_ap,
    json_extracted.geo_adc,
    json_extracted.registered_without_booking,
    json_extracted.prepack_dates_to,
    json_extracted.prepack_dates_from,
    json_extracted.prepack_regular_price,
    json_extracted.action_price,
    json_extracted.rc_type,
    users.name AS "user",
    json_extracted.version,
    json_extracted.ats,
    json_extracted.uts
FROM
    json_extracted
    LEFT JOIN users ON users.id :: text = json_extracted.user_id
    LEFT JOIN (
        SELECT
            DISTINCT CASE
                templates_cons.frmt
                WHEN 'gm' :: text THEN '"ГМ"' :: text
                WHEN 'mk' :: text THEN '"МК"' :: text
                WHEN 'mm' :: text THEN '"ММ"' :: text
                ELSE NULL :: text
            END AS frmt,
            templates_cons.uni_dmp_name,
            CASE
                WHEN templates_cons.frmt = 'gm' :: text
                AND templates_cons.uni_dmp_name = 'Стеллаж' :: text THEN 'Полка' :: text
                ELSE templates_cons.uni_site_name
            END AS uni_site_name
        FROM
            templates_cons
    ) mp_names ON mp_names.frmt = json_extracted.whs_format
    AND mp_names.uni_dmp_name = json_extracted.dmp_name
WHERE
    NOT json_extracted.scs_stable_guid IS NULL
    AND NOT json_extracted.name IS NULL
ORDER BY
    json_extracted.scs_stable_guid,
    json_extracted.tp_code,
    json_extracted.version DESC