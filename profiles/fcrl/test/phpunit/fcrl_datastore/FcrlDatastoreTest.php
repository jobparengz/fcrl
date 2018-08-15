<?php

/**
 * @file
 * Base phpunit tests for FcrlDatastoreFastImport class.
 */

/**
 * FcrlDatastoreFastImport class.
 */
class FcrlDatastoreTest extends \PHPUnit_Framework_TestCase {

  /**
   * Test updateFromFileUri.
   *
   * @covers FcrlDatastore::updateFromFileUri
   */
  public function testUpdateFromFileUri() {
    // Create a stub for the FcrlDatastore class.
    $fcrlDatastorestub = $this->getMockBuilder(FcrlDatastore::class)
      ->setMethods(['updateFromFile'])
      ->disableOriginalConstructor()
      ->disableOriginalClone()
      ->getMock();

    // Configure the stub.
    $fcrlDatastorestub->expects($this->once())
      ->method('updateFromFile')
      ->willReturn(TRUE);

    $testfileuri = __DIR__ . '/data/countries.csv';
    // Calling $stub->doSomething() will now return
    // 'foo'.
    $this->assertEquals(TRUE, $fcrlDatastorestub->updateFromFileUri($testfileuri));
  }

  /**
   * Test updateFromFileUri when no file is provided.
   *
   * @covers FcrlDatastore::updateFromFileUri
   */
  public function testUpdateFromFileUriNoFile() {
    // Create a stub for the FcrlDatastore class.
    $fcrlDatastorestub = $this->getMockBuilder(FcrlDatastore::class)
      ->setMethods(['updateFromFile'])
      ->disableOriginalConstructor()
      ->disableOriginalClone()
      ->getMock();

    // Configure the FcrlDatastorestub method.
    $fcrlDatastorestub->expects($this->never())
      ->method('updateFromFile')
      ->willReturn(TRUE);

    $this->assertEquals(FALSE, $fcrlDatastorestub->updateFromFileUri());
  }

  /**
   * Test importByCli.
   *
   * @covers FcrlDatastore::importByCli
   */
  public function testImportByCli() {
    $feedsSourceStub = $this->getMockBuilder(FeedsSource::class)
      ->setMethods(['import'])
      ->disableOriginalConstructor()
      ->disableOriginalClone()
      ->getMock();

    $feedsSourceStub->expects($this->once())
      ->method('import')
      ->willReturn(FEEDS_BATCH_COMPLETE);

    // Create a stub for the FcrlDatastore class.
    $fcrlDatastoreStub = $this->getMockBuilder(FcrlDatastore::class)
      ->setMethods(['source', 'setupSourceBackground'])
      ->disableOriginalConstructor()
      ->disableOriginalClone()
      ->getMock();

    // Configure the FcrlDatastorestub method.
    $fcrlDatastoreStub->expects($this->once())
      ->method('source')
      ->willReturn($feedsSourceStub);

    // Configure the FcrlDatastorestub method.
    $fcrlDatastoreStub->expects($this->once())
      ->method('setupSourceBackground')
      ->willReturn(TRUE);

    $this->assertEquals(TRUE, $fcrlDatastoreStub->importByCli());
  }

  /**
   * Test importByCli when Feeds Source preparation fails.
   *
   * @covers FcrlDatastore::importByCli
   */
  public function testImportByCliFailedSourcePreparation() {
    $feedsSourceStub = $this->getMockBuilder(FeedsSource::class)
      ->setMethods(['import'])
      ->disableOriginalConstructor()
      ->disableOriginalClone()
      ->getMock();

    $feedsSourceStub->expects($this->never())
      ->method('import');

    // Create a stub for the FcrlDatastore class.
    $fcrlDatastoreStub = $this->getMockBuilder(FcrlDatastore::class)
      ->setMethods(['source', 'setupSourceBackground'])
      ->disableOriginalConstructor()
      ->disableOriginalClone()
      ->getMock();

    // Configure the FcrlDatastorestub method.
    $fcrlDatastoreStub->expects($this->once())
      ->method('source')
      ->willReturn($feedsSourceStub);

    // Configure the FcrlDatastorestub method.
    $fcrlDatastoreStub->expects($this->once())
      ->method('setupSourceBackground')
      ->willReturn(FALSE);

    $this->assertEquals(FALSE, $fcrlDatastoreStub->importByCli());
  }

  /**
   * Test importByCli when the Feed Source import fails.
   *
   * @covers FcrlDatastore::importByCli
   */
  public function testImportByCliFailImport() {
    $feedsSourceStub = $this->getMockBuilder(FeedsSource::class)
      ->setMethods(['import'])
      ->disableOriginalConstructor()
      ->disableOriginalClone()
      ->getMock();

    $feedsSourceStub->expects($this->once())
      ->method('import')
      ->will($this->throwException(new Exception()));

    // Create a stub for the FcrlDatastore class.
    $fcrlDatastoreStub = $this->getMockBuilder(FcrlDatastore::class)
      ->setMethods(['source', 'setupSourceBackground'])
      ->disableOriginalConstructor()
      ->disableOriginalClone()
      ->getMock();

    // Configure the FcrlDatastorestub method.
    $fcrlDatastoreStub->expects($this->once())
      ->method('source')
      ->willReturn($feedsSourceStub);

    // Configure the FcrlDatastorestub method.
    $fcrlDatastoreStub->expects($this->once())
      ->method('setupSourceBackground')
      ->willReturn(TRUE);

    $this->assertEquals(FALSE, $fcrlDatastoreStub->importByCli());
  }

}
