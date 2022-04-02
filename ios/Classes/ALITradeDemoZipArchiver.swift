//
//  ALITradeDemoZipArchiver.swift
//  flutter_baichuan
//
//  Created by dmcb on 2021/8/26.
//

import Foundation
import SSZipArchive
import WindmillWeaver

class ALITradeDemoZipArchiverOp: NSObject, TRVZipOperationProtocol {
    var innerArchiver: SSZipArchive?
    var zipFile: String?

    func unzipOpenFile(_ zipFile: String!) -> Bool {
        innerArchiver = SSZipArchive(path: zipFile)
        self.zipFile = zipFile
        return true
    }

    func unzipCloseFile() -> Bool {
        return true
    }

    func unzipFile(to path: String!, overWrite overwrite: Bool) -> Bool {
        return SSZipArchive.unzipFile(atPath: zipFile ?? "", toDestination: path)
    }
}

class ALITradeDemoZipArchiver: NSObject,TRVZipArchiveProtocol {
    func zipArchiverInstance() -> TRVZipOperationProtocol! {
        return ALITradeDemoZipArchiverOp()
    }
    
    
}
