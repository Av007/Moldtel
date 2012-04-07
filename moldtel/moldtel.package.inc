<?php

/** 
 * @file - use as include file to Drupal 7.x molude 
 * @class - This class checks optimized abonement, get current abonament and 
 * calculates prices. Also class get optimizated package(s) depending on user 
 * bill data.
 * 
 * @version 1.0
 */

class MoldtelPackage
{
    /**
     **** Variables ****
     * 
     * @var $values type array() current users values
     * @var $tarifs type array() current tarifs from db
     * @var $fields type array() current active fields
     * @var $abonaments type array() all active abonaments (marks as in db)
     * @var $local_min type array() abonament minutes include fields
     */
    var $values;
    var $tarifs;
    var $fields = array('local_min', 'national_min', 'mob_min', 'inter_min', 'rus_min', 'eu_usa_min');
    var $abonaments = array('st', 'ec', 'in');
    var $local_min = array('local_min', 'national_min');
    
    public function __construct($values, $tarifs) {
        $this->values = $values;
        $this->tarifs = $tarifs;
    }

    // @deprecated 
    /*
    private function get_abonament_price($abonament_name) {
        $local_min = 0; // local minutes
        $diff_minutes = 0;
        // $other_min = 0; // all minutes exept local
        foreach ($this->values as $k => $value) {
            if (in_array($k, $this->local_min))
                $local_min += $value;
        }
        $diff_minutes = intval($this->tarifs[$abonament_name]['minutes'] - $local_min);
        if($diff_minutes < 0)
            $diff_minutes = 0;
        foreach ($this->values as $k => $value) {
            if (in_array($k, $this->fields) && !in_array($k, $this->local_min))
                $other_min += $value;
        }
        // (($diff_minutes + $other_min) * $this->tarifs[$abonament_name . ' add']['price']) +
        $total_price =  $this->tarifs[$abonament_name]['price'];
        return $total_price;
    }
    */
    
    /**
     * Function return array with two subarray current and optimum abonaments
     * 
     * @return type array() 
     * 1) optimum - array of abonament with name and price witch selected as optimized (low price)
     * 2) current - array of abonament with name and price witch selected as users current
     */
    public function get_current_abonament_price()
    {
        // get current abonament data
        $abnm_price[$this->values['abonament']] = $this->tarifs[$this->values['abonament']]['price'];
        $cur_abnm = array('name' => $this->values['abonament'], 'price' => $abnm_price[$this->values['abonament']]);
        // get other abonament data
        foreach ($this->abonaments as $abonament_name) {
            if ($abonament_name != $this->values['abonament']) {
                $abnm_price[$abonament_name] = $this->tarifs[$abonament_name]['price'];
            }
        }
        foreach ($abnm_price as $key => $value) {
            if (isset($op_abnm) && $value < $op_abnm)
                $op_abnm = array('name' => $key, 'price' => $value);
            elseif (!isset($op_abnm))
                $op_abnm = array('name' => $key, 'price' => $value);
        }
        return array('optimum' => $op_abnm, 'current' => $cur_abnm);
    }

    /**
     * This function return array of packages that can be apply
     * 
     * @param $op_abnm type array() - optimized abonament. Use for dividing local 
     * including in abonament minutes.
     * @return array() of packages
     */
    public function get_packege_price($op_abnm) {
        $result = array();
        $diff_min = 0;
        // dividing minutes that included in optimized abonament
        $this->values['local_min'] -= $this->tarifs[$op_abnm['optimum']['name']]['minutes'];
        if ($this->values['local_min'] < 0) {
            $this->values['national_min'] += $this->values['local_min'];
        }
        foreach ($this->values as $key => $value) {
            if ($value > 0) {
                foreach ($this->tarifs as $tarif) {
                    if ((strpos($tarif['tarif_name'], $key) !== FALSE) && (strpos($tarif['tarif_name'], 'mix') == FALSE)) {
                        $diff_min = $tarif['minutes'] - $value;
                        if (($diff_min >= 0) && isset($result[$key]) && (($result[$key]['diff_min'] < 0) || ($diff_min < $result[$key]['diff_min']) && ($result[$key]['diff_min'] > 0)))
                            $result[$key] = array('price' => $tarif['price'], 'name' => $tarif['tarif_name'], 'diff_min' => $diff_min);
                        elseif (($diff_min < 0) && isset($result[$key]) && ($diff_min > $result[$key]['diff_min']))
                            $result[$key] = array('price' => $tarif['price'], 'name' => $tarif['tarif_name'], 'diff_min' => $diff_min);
                        elseif (!isset($result[$key]))
                            $result[$key] = array('price' => $tarif['price'], 'name' => $tarif['tarif_name'], 'diff_min' => $diff_min);
                    }
                }
            }
        }
        return $result;
    }
    
    /**
     * This function return array of mix packages that can be apply. Mix package 
     * included a few type of simple packages and have one price.
     * 
     * @return array() of mix packages
     * @method return array('type' => array('diff_min' => value, 'name' => value,))
     * @var diff_min - delta between used minutes and including minutes in current package
     * @var name - name of current field
     * @var field - included form fields
     * @example array('50' => array('diff_min' => -15, 'name' => lical_min_15))
     */
    public function get_mix_price() {
        $result = array();
        foreach ($this->tarifs as $value) {
            if (strpos($value['tarif_name'], 'mix') !== FALSE) {
                // 0 - mix, 1 - type, 2 - name
                $mix_array[] = array(
                    'value' => $value,
                    'map' => explode(' ', $value['tarif_name']),
                );
            }
        }
        foreach ($this->values as $k => $v) {
            foreach ($mix_array as $ma) {
                if (isset($value) && ($k == $ma['map'][2]) && $ma['value']['minutes'] >= $v) {
                        $result[$ma['map'][1]][$k] = $ma['value']['minutes'] - $v;
                }
            }
        }
        foreach ($result as $key => $value) {
            $i = 0;
            if (isset($temp)) {
                foreach (array_keys($temp) as $v) {
                    foreach (array_keys($value) as $val) {
                        if ($v == $val) {
                            $i++;
                        }
                    }
                }
            } else {
                $temp = $value;
                $tmp_count = count($value);
                $tmp_type = $key;
            }
            if (($i == $tmp_count) && ($tmp_count == count($value))) {
                if ($tmp_type > $key)
                    unset($result[$tmp_type]);
                else
                    unset($result[$key]);
            }
            $temp = $value;
            $tmp_count = count($value);
            $tmp_type = $key;
        }
        return $result;
    }
}
?>
