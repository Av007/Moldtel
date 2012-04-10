<?php

/** 
 * @file - use as include file to Drupal 7.x module 
 * @class - This class gets plans prices for actual users minutes. Also class 
 *          gets optimized package(s) depending on user bill data.
 * 
 * @version 1.1
 */

class MoldtelPackage
{
    /**
     **** Variables ****
     * 
     * @var $values type array() current users values
     * @var $tarifs type array() current tarifs from db
     * @var $fields type array() current active fields
     * @var $local_min type array() abonament minutes include fields
     * @var $loc_min type int summa of all interior network minutes
     */
    var $values;
    var $tarifs;
    var $fields = array('local_min', 'national_min', 'mob_min', 'inter_min', 'rus_min', 'eu_usa_min');
    var $local_min = array('local_min', 'national_min');
    var $loc_min = 0;
    
    public function __construct($values, $tarifs) {
        $chk_vals = array();
        // set up only useful values
        foreach (array_intersect($this->fields, array_keys($values)) as $key => $value)
            $chk_vals[$value] = $values[$value];
        $this->values = $chk_vals;
        $this->tarifs = $tarifs;
    }
    
    public function GetResult()
    {
        $plans = $this->GetOptimizedPlan();
        $packages = $this->GetOptimizedPackege($plans);
        $mixes = $this->GetMixPrice($plans);
        $result = $this->GetPackagesName($plans, $packages, $mixes);
        return $result;
    }
    
    /**
     * Function return array with two subarray with currents and optimum plans
     * 
     * @return type array() 
     * 1) optimum - array of plan with name and price witch was selected as optimized
     * 2) current - array of plan with name and price witch  was selected as users current
     */
    private function GetOptimizedPlan()
    {
        // get other abonament data
        foreach ($this->tarifs as $tarif) {
            if($tarif['type'] == 'plan') {
                $k = $this->tarifs[$tarif['tarif_name']]['price'] / $this->tarifs[$tarif['tarif_name']]['minutes'];
                $plan_price[$tarif['tarif_name']] = $this->getPrice($this->values['local_min'], $this->tarifs[$tarif['tarif_name']]['minutes'], $this->tarifs[$tarif['tarif_name']]['price'], $k, $this->tarifs[$tarif['tarif_name'] . ' add']['price']);
            }
        }
        
        foreach ($plan_price as $key => $value) {
            if (isset($op_plan) && ($value < $op_plan['price'])) {
                $cur_plan = $op_plan;
                $op_plan = array('name' => $key, 'price' => $value);
            }
            elseif (!isset($op_plan))
                $op_plan = array('name' => $key, 'price' => $value);
            else
                $cur_plan = array('name' => $key, 'price' => $value);
        }
        return array('optimum' => $op_plan, 'current' => $cur_plan);
    }

    /**
     * This function return array of packages that can be apply
     * 
     * @param $op_abnm type array() - optimized abonament. Use for dividing local 
     *                              including in abonament minutes.
     * @return array() of packages
     */
    private function GetOptimizedPackege($op_abnm) {
        // dividing minutes that included in optimized abonament
        $this->values['local_min'] -= $this->tarifs[$op_abnm['optimum']['name']]['minutes'];
        if ($this->values['local_min'] < 0) {
            $this->values['local_min'] = 0;
        }
        
        foreach ($this->values as $key => $value) {
            if ($value > 0) {
                foreach ($this->tarifs as $tarif) {
                    // compare type package by filds
                    if ((strpos($tarif['tarif_name'], $key) !== FALSE) && (strpos($tarif['tarif_name'], 'mix ') === FALSE) && (strpos($tarif['tarif_name'], ' add') === FALSE)) {
                        if (in_array($key, $this->local_min))
                            $add_tarif = $this->tarifs[$op_abnm['optimum']['name']  . ' add']['price'];
                        else
                            $add_tarif = $this->tarifs[$key . ' add']['price'];
                        $k = $tarif['price'] / $tarif['minutes'];
                        $plan_price[$tarif['tarif_name']] = array( 'price' => $this->getPrice($value, $tarif['minutes'], $tarif['price'], $k, $add_tarif),
                            'field' => $key);
                    }
                }
            }
        }
        
        foreach ($plan_price as $key => $value) {
            if (isset($result[$value['field']]) && ($value['price'] < $result[$value['field']]['price']) && ($result[$value['field']]['field'] == $value['field'])) {
                $result[$value['field']] = array('name' => $key, 'price' => $value['price'], 'field' => $value['field']);
            } elseif (!isset($result[$value['field']]))
                $result[$value['field']] = array('name' => $key, 'price' => $value['price'], 'field' => $value['field']);
        }
        return $result;
    }
    
    /**
     * This function return array of mix packages that can be applied. Mix package 
     * included several type of simple packages and has one price.
     * 
     * @return array() of mix packages
     * @method return array('type' => array('price' => value, 'name' => value,))
     * @var price - current mix price according user's minutes
     * @var name - name of current field
     * @var field - included form fields
     * @example array('50' => array('price' => 156, 'name' => lical_min_15))
     */
    private function GetMixPrice($op_abnm) {
        // parse mix values
        foreach ($this->tarifs as $value) {
            if (strpos($value['tarif_name'], 'mix') !== FALSE) {
                // 0 - mix, 1 - type, 2 - name
                $mix_array[] = array(
                    'value' => $value,
                    'map' => explode(' ', $value['tarif_name']),
                );
            }
        }
        foreach ($this->values as $key => $v) {
            foreach ($mix_array as $ma) {
                if (($key == $ma['map'][2]) && ($v != 0)) {
                    if ($key == 'national_min')
                        $add_tarif = $this->tarifs[$op_abnm['optimum']['name'] . ' add']['price'];
                    else
                        $add_tarif = $this->tarifs[$key . ' add']['minutes'];
                    $k = $ma['value']['price'] / $ma['value']['minutes'];
                    $add_mix = $this->getPrice($v, $ma['value']['minutes'], $ma['value']['price'], $k, $add_tarif);
                    if($add_mix > $ma['map'][1])
                        $result[$ma['map'][1]] += $add_mix - $ma['map'][1];
                    elseif(!isset ($result[$ma['map'][1]]))
                        $result[$ma['map'][1]] = $ma['value']['price'];
                    $add_mix = 0;
                }
            }
        }
        
        // select cheapest mix packet
        foreach ($result as $key => $value) {
            if (isset($op_mix) && ($value < $op_mix['price'])) {
                $op_mix = array('name' => $key, 'price' => $value);
            } elseif (!isset($op_mix))
                $op_mix = array('name' => $key, 'price' => $value);
        }
        return $op_mix;
    }
    
    /**
     * Return packages name code for labels
     */
    private function GetPackagesName($plans, $packages, $mixes) {
        // for plans
        $result['current'] = array('name' => $this->tarifs[$plans['current']['name']]['name'],
            'price' => $plans['current']['price']);
        $result['optimum'] = array('name' => $this->tarifs[$plans['optimum']['name']]['name'],
                'price' => $plans['optimum']['price']);
        // for package
        foreach ($packages as $key => $value) {
                $result[] = array('name' => $this->tarifs[$value['name']]['name'],
                    'price' => $value['price']);
        }
        // for mixes
        foreach ($this->tarifs as $value)
        {
            if (strpos($value['tarif_name'], 'mix ' . $mixes['name']) !== FALSE) 
            {
                $result['mix'] = array('name' => $value['name'],
                    'price' => $mixes['price']);
            }
        }
        return $result;
    }
    
    /** 
     * Main formula for this task:
     * S = (S_pac / t_pac * t) + a * (t - t_pack)
     * 
     * @param type $usr_min - users minutes
     * @param type $pack_min - package/plan minutes
     * @param type $price - package/plan price
     * @param type $add_price - adding price for overflow plan per minute
     * @param type $add_min - adding minutes for overflow plan
     * @return type float
     */
    protected function getPrice($usr_min, $pack_min, $price, $add_price, $add_min)
    {
        $usr_price = $add_min * ($usr_min - $pack_min);
        if($usr_price < 0)
            $usr_price = 0;
        $usr_price += $add_price * $usr_min;
        return max($usr_price, $price);
    }
}
?>
