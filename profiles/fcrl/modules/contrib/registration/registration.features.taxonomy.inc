<?php
/**
 * @file
 * registration.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function registration_taxonomy_default_vocabularies() {
  return array(
    'abuyog' => array(
      'name' => 'RVIII Leyte Abuyog Brgy',
      'machine_name' => 'abuyog',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'agusan_del_norte' => array(
      'name' => 'CARAGA Agusan del Norte Municipality',
      'machine_name' => 'agusan_del_norte',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 6,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'albay' => array(
      'name' => 'RV Albay Municipality',
      'machine_name' => 'albay',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -1,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'anahawan' => array(
      'name' => 'RVIII  Southern Leyte Anahawan Brgy',
      'machine_name' => 'anahawan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'bacacay' => array(
      'name' => 'RV Albay Bacacay Brgy',
      'machine_name' => 'bacacay',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'bacon_district_sorsogon_city' => array(
      'name' => 'RV Sorsogon Bacon District, Sorsogon City Brgy',
      'machine_name' => 'bacon_district_sorsogon_city',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'balangiga' => array(
      'name' => 'RVIII Eastern Samar* Balangiga Brgy',
      'machine_name' => 'balangiga',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'balatan' => array(
      'name' => 'RV Camsur Balatan Brgy',
      'machine_name' => 'balatan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'balud' => array(
      'name' => 'RV Masbate Balud Brgy',
      'machine_name' => 'balud',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'barobo' => array(
      'name' => 'CARAGA Surigao del Sur Barobo Brgy',
      'machine_name' => 'barobo',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'basey' => array(
      'name' => 'RVIII Western Samar Basey Brgy',
      'machine_name' => 'basey',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'bato' => array(
      'name' => 'RV Camsur Bato Brgy',
      'machine_name' => 'bato',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'bayabas' => array(
      'name' => 'CARAGA Agusan del Sur Bayabas Brgy',
      'machine_name' => 'bayabas',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 9,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'buenavista' => array(
      'name' => 'CARAGA Agusan del Norte Buenavista Brgy',
      'machine_name' => 'buenavista',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'bula' => array(
      'name' => 'RV Camsur Bula Brgy',
      'machine_name' => 'bula',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'butuan' => array(
      'name' => 'CARAGA Agusan del Norte Butuan Brgy',
      'machine_name' => 'butuan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 1,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'cabadbaran_city' => array(
      'name' => 'CARAGA Agusan del Norte Cabadbaran City Brgy',
      'machine_name' => 'cabadbaran_city',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 2,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'cagwait' => array(
      'name' => 'CARAGA Surigao del Sur Cagwait Brgy',
      'machine_name' => 'cagwait',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'calbiga' => array(
      'name' => 'RVIII Western Samar* Calbiga Brgy',
      'machine_name' => 'calbiga',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'camsur' => array(
      'name' => 'RV Camarines Sur Municipality',
      'machine_name' => 'camsur',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'caraga_provinces' => array(
      'name' => 'CARAGA Provinces',
      'machine_name' => 'caraga_provinces',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'carmen' => array(
      'name' => 'CARAGA Agusan del Norte Carmen Brgy',
      'machine_name' => 'carmen',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 3,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'catbalogan_city' => array(
      'name' => 'RVIII Western Samar*  Catbalogan City Brgy',
      'machine_name' => 'catbalogan_city',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'cawayan' => array(
      'name' => 'RV Masbate Cawayan Brgy',
      'machine_name' => 'cawayan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'daram' => array(
      'name' => 'RVIII Western Samar* Daram Brgy',
      'machine_name' => 'daram',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'del_gallego' => array(
      'name' => 'RV Camsur Del Gallego Brgy',
      'machine_name' => 'del_gallego',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'dulag' => array(
      'name' => 'RVIII Leyte Dulag Brgy',
      'machine_name' => 'dulag',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'eastern_samar' => array(
      'name' => 'RVIII Eastern Samar Municipality',
      'machine_name' => 'eastern_samar',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'eastern_samar_0' => array(
      'name' => 'RVIII Eastern Samar* Municipality',
      'machine_name' => 'eastern_samar_0',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'esperanza' => array(
      'name' => 'RV Masbate Esperanza Brgy',
      'machine_name' => 'esperanza',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'gen_macarthur' => array(
      'name' => 'RVIII Eastern Samar Gen. MacArthur Brgy',
      'machine_name' => 'gen_macarthur',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'gender' => array(
      'name' => 'Gender',
      'machine_name' => 'gender',
      'description' => 'Either male or female',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -5,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'giporlos' => array(
      'name' => 'RVIII Eastern Samar* Giporlos Brgy',
      'machine_name' => 'giporlos',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'group_type' => array(
      'name' => 'Group Type',
      'machine_name' => 'group_type',
      'description' => 'Either a part of a group or an individual only.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -4,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'guiuan' => array(
      'name' => 'RVIII Eastern Samar* Guiuan Brgy',
      'machine_name' => 'guiuan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'hernani' => array(
      'name' => 'RVIII Eastern Samar Hernani Brgy',
      'machine_name' => 'hernani',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'hinatuan' => array(
      'name' => 'CARAGA Surigao del Sur Hinatuan Brgy',
      'machine_name' => 'hinatuan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'hinunangan' => array(
      'name' => 'RVIII Southern Leyte Hinunangan Brgy',
      'machine_name' => 'hinunangan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'hinundayan' => array(
      'name' => 'RVIII  Southern Leyte Hinundayan Brgy',
      'machine_name' => 'hinundayan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'jabonga' => array(
      'name' => 'CARAGA Agusan del Norte Jabonga Brgy',
      'machine_name' => 'jabonga',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 4,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'javier' => array(
      'name' => 'RVIII Leyte Javier Brgy',
      'machine_name' => 'javier',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'jiabong' => array(
      'name' => 'RVIII Western Samar* Jiabong Brgy',
      'machine_name' => 'jiabong',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'lawa_an' => array(
      'name' => 'RVIII Eastern Samar* Lawa-an Brgy',
      'machine_name' => 'lawa_an',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'legaspi_city' => array(
      'name' => 'RV Albay Legaspi City Brgy',
      'machine_name' => 'legaspi_city',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'leyte' => array(
      'name' => 'RVIII Leyte Municipality',
      'machine_name' => 'leyte',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'libmanan' => array(
      'name' => 'RV Camsur Libmanan Brgy',
      'machine_name' => 'libmanan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'liloan' => array(
      'name' => 'RVIII Southern Leyte Liloan Brgy',
      'machine_name' => 'liloan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'lupi' => array(
      'name' => 'RV Camsur Lupi Brgy',
      'machine_name' => 'lupi',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'mac_arthur' => array(
      'name' => 'RVIII Leyte Mac Arthur Brgy',
      'machine_name' => 'mac_arthur',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'magallanes' => array(
      'name' => 'CARAGA Agusan del Norte Magallanes Brgy',
      'machine_name' => 'magallanes',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 5,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'manito' => array(
      'name' => 'RV Albay Manito Brgy',
      'machine_name' => 'manito',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'marabut' => array(
      'name' => 'RVIII Western Samar Marabut Brgy',
      'machine_name' => 'marabut',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'masbate' => array(
      'name' => 'RV Masbate Municipality',
      'machine_name' => 'masbate',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'mayorga' => array(
      'name' => 'RVIII Leyte Mayorga Brgy',
      'machine_name' => 'mayorga',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'mercedes' => array(
      'name' => 'RVIII Eastern Samar* Mercedes Brgy',
      'machine_name' => 'mercedes',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'milagros' => array(
      'name' => 'RV Masbate Milagros Brgy',
      'machine_name' => 'milagros',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'minalabac' => array(
      'name' => 'RV Camsur Minalabac Brgy',
      'machine_name' => 'minalabac',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'motiong' => array(
      'name' => 'RVIII Western Samar* Motiong Brgy',
      'machine_name' => 'motiong',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'nasipit' => array(
      'name' => 'CARAGA Agusan del Norte Nasipit Brgy',
      'machine_name' => 'nasipit',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 7,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'others' => array(
      'name' => 'others',
      'machine_name' => 'others',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -3,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'palo' => array(
      'name' => 'RVIII Leyte Palo Brgy',
      'machine_name' => 'palo',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'paranas' => array(
      'name' => 'RVIII Western Samar* Paranas Brgy',
      'machine_name' => 'paranas',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'pasacao' => array(
      'name' => 'RV Camsur Pasacao Brgy',
      'machine_name' => 'pasacao',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'pinabacdao' => array(
      'name' => 'RVIII Western Samar*  Pinabacdao Brgy',
      'machine_name' => 'pinabacdao',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'placer' => array(
      'name' => 'RV Masbate Placer Brgy',
      'machine_name' => 'placer',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'prieto_diaz' => array(
      'name' => 'RV Sorsogon Prieto Diaz Brgy',
      'machine_name' => 'prieto_diaz',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'quinapondan' => array(
      'name' => 'RVIII Eastern Samar Quinapondan Brgy',
      'machine_name' => 'quinapondan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'quinapondan_0' => array(
      'name' => 'VIII Eastern Samar* Quinapondan* Brgy',
      'machine_name' => 'quinapondan_0',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'ragay' => array(
      'name' => 'RV Camsur Ragay Brgy',
      'machine_name' => 'ragay',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'rapu_rapu' => array(
      'name' => 'RV Albay Rapu-Rapu Brgy',
      'machine_name' => 'rapu_rapu',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'regionstag' => array(
      'name' => 'Regions',
      'machine_name' => 'regionstag',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'rv_provinces' => array(
      'name' => 'Region V Provinces',
      'machine_name' => 'rv_provinces',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -2,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'rviii_provinces' => array(
      'name' => 'Region VIII Provinces',
      'machine_name' => 'rviii_provinces',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'salcedo' => array(
      'name' => 'RVIII Eastern Samar Salcedo Brgy',
      'machine_name' => 'salcedo',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'salcedo_0' => array(
      'name' => 'VIII Eastern Samar* Salcedo* Brgy',
      'machine_name' => 'salcedo_0',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'san_fernando' => array(
      'name' => 'RV Camsur San Fernando Brgy',
      'machine_name' => 'san_fernando',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'san_juan' => array(
      'name' => 'RVIII  Southern Leyte San Juan Brgy',
      'machine_name' => 'san_juan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'san_pascual' => array(
      'name' => 'RV Camsur San Pascual Brgy',
      'machine_name' => 'san_pascual',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'san_sebastian' => array(
      'name' => 'RVIII Western Samar* San Sebastian Brgy',
      'machine_name' => 'san_sebastian',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'santo_domingo' => array(
      'name' => 'RV Albay Santo Domingo Brgy',
      'machine_name' => 'santo_domingo',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'silago' => array(
      'name' => 'RVIII  Southern Leyte Silago Brgy',
      'machine_name' => 'silago',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'sipocot' => array(
      'name' => 'RV Camsur Sipocot Brgy',
      'machine_name' => 'sipocot',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'sorsogon' => array(
      'name' => 'RV Sorsogon Municipality',
      'machine_name' => 'sorsogon',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'southern_leyte' => array(
      'name' => 'RVIII Southern Leyte Municipality',
      'machine_name' => 'southern_leyte',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'st_bernard' => array(
      'name' => 'RVIII  Southern Leyte St. Bernard Brgy',
      'machine_name' => 'st_bernard',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'surigao_del_sur' => array(
      'name' => 'CARAGA Surigao del Sur Municipality',
      'machine_name' => 'surigao_del_sur',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'tacloban_city' => array(
      'name' => 'RVIII Leyte Tacloban City Brgy',
      'machine_name' => 'tacloban_city',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'talalora' => array(
      'name' => 'RVIII Western Samar* Talalora Brgy',
      'machine_name' => 'talalora',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'tanauan' => array(
      'name' => 'RVIII Leyte Tanauan Brgy',
      'machine_name' => 'tanauan',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'tolosa' => array(
      'name' => 'RVIII Leyte Tolosa Brgy',
      'machine_name' => 'tolosa',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'tubay' => array(
      'name' => 'CARAGA Agusan del Norte Tubay Brgy',
      'machine_name' => 'tubay',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 8,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'type_of_beneficiaries' => array(
      'name' => 'Type of Beneficiaries',
      'machine_name' => 'type_of_beneficiaries',
      'description' => 'Either the beneficiary is a Senior or a Youth.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'villareal' => array(
      'name' => 'RVIII Western Samar*  Villareal Brgy',
      'machine_name' => 'villareal',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'western_samar' => array(
      'name' => 'RVIII Western Samar Municipality',
      'machine_name' => 'western_samar',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'western_samar_0' => array(
      'name' => 'RVIII Western Samar* Municipality',
      'machine_name' => 'western_samar_0',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'zumarraga' => array(
      'name' => 'RVIII Western Samar* Zumarraga Brgy',
      'machine_name' => 'zumarraga',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
