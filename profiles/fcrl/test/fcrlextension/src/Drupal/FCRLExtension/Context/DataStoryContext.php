<?php

namespace Drupal\FCRLExtension\Context;

use Behat\Gherkin\Node\TableNode;

/**
 * Defines application features from the specific context.
 */
class DataStoryContext extends RawFCRLEntityContext{

    public function __construct(){
        parent::__construct(
            'node',
            'fcrl_data_story'
        );
    }

    /**
     * Creates data stories from table.
     *
     * @Given data stories:
     */
    public function addDataStories(TableNode $datastoriestable){
        parent::addMultipleFromTable($datastoriestable);
    }
}
