<?php

/**
 * @file - use as include file to Drupal 7.x molude 
 * @class - This class compare packages by adding tarrif and mix package.
 * 
 * @version 1.0
 */

class MoldtelController
{
    var $values;
    var $abonaments;
    var $packages;
    var $mixes;
    var $tarifs;
    var $optimum_price = array();
    var $current_price = array();
    var $result_price = array();
    var $mix_price = array();
    var $fields = array('local_min', 'national_min', 'mob_min', 'inter_min', 'rus_min', 'eu_usa_min');
    
    public function __construct($values, $abonaments, $packages, $mixes, $tarifs) {
        $this->values = $values;
        $this->abonaments = $abonaments;
        $this->packages = $packages;
        $this->mixes = $mixes;
        $this->tarifs = $tarifs;
        foreach (array_intersect($this->fields, array_keys($values)) as $value)
        {
            $this->optimum_price[$value] = 0;
            $this->result_price[$value] = 0;
        }
    }
    /**
     * Main function in class that call useful methods and return result
     *
     * @return - array of data
     * @example array('optimum_price' => $optimum_price, 'current_price' => $current_price, 'packages_name' => $packages_name);
     */
    public function DisplayResult()
    {
        $this->getValuesPrices();
        $this->getDiffPrices();
        $optimum_price = $this->getSummPrice();
        $current_price = $this->getOldSummPrice();
        $packages_name = $this->getPackagesName();
        return array('optimum_price' => $optimum_price, 'current_price' => $current_price, 'packages_name' => $packages_name);
    }
    /**
     * Get values minutes and make price by optimum abonament
     */
    private function getValuesPrices()
    {
        foreach ($this->values as $key => $value) {
            if (in_array($key, $this->fields))
            {
                $this->optimum_price[$key] = $value * $this->tarifs[$this->abonaments['optimum']['name'] . ' add']['price'];
            }
        }
        $this->current_price = $this->optimum_price;
    }
    /**
     * Compare all package between each other - unuseful unset.
     */
    private function getDiffPrices()
    {
        foreach ($this->packages as $key=>$value)
        {
            foreach ($this->optimum_price as $k=>$v) {
                if ($key == $k && $value['price'] > $v)
                {
                    $this->result_price[$key] = $v;
                    //$this->result_price[$key]['type'] = 'default';
                    unset($this->packages[$key]);
                }
                else {
                    unset($this->optimum_price[$key]);
                    $this->result_price[$key] = $value;
                    //$this->result_price[$key]['type'] = 'package';
                }
            }
        }
        $result = 0;
        foreach ($this->result_price as $price)
        {
            $result += $price['price'];
        }
        if (count($this->mixes) > 0)
        {
            foreach ($this->mixes as $key=>$mix) {
                if ($key < $result)
                {
                    $add_to_cmp_mix = 0;
                    foreach ($this->fields as $value) {
                        if (isset($mix[$value]))
                        {
                            $add_to_cmp_mix += $this->result_price[$value]['price'];
                        }
                    }
                    if ($add_to_cmp_mix < $key) 
                    {
                        unset($this->mixes[$key]);
                    }
                }
                else
                    unset($this->mixes[$key]);
            }
        }
        if (count($this->mixes) > 1)
        {
            echo "error";
        }
    }
    /**
     * Get new optimized price.
     */
    private function getSummPrice()
    {
        $result = 0;
        foreach ($this->optimum_price as $value) {
            $result += $value;
        }
        foreach ($this->packages as $value) {
            $result += $value['price'];
        }
        foreach ($this->mixes as $k=>$value) {
            $result += $k;
        }
        // add optimum abonament price
        $result += $this->abonaments['optimum']['price'];
        return $result;
    }
    /**
     * Get current user price.
     */
    private function getOldSummPrice()
    {
        $result = 0;
        foreach ($this->current_price as $value) {
            $result += $value;
        }
        return $result;
    }
    /**
     * Return packages name code for labels
     */
    private function getPackagesName()
    {
        $result = array();
        foreach ($this->packages as $key => $value) {
            $result[] = $value['name'];
        }
        foreach ($this->mixes as $key => $value) {
            $result[] = 'mix '. $key;
        }
        foreach ($result as &$value) {
            if(strpos($value, 'mix') !== FALSE)
            {
                foreach ($this->tarifs as $v) {
                    if(strpos($v['tarif_name'], $value) !== FALSE)
                    {
                        $value = $this->tarifs[$v['tarif_name']]['name'];
                    }
                }
            }
            else
                $value = $this->tarifs[$value]['name'];
        }
        return $result;
    }
}
?>
