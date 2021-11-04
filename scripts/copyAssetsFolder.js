"use strict";

var path = require("path");
var fs = require("fs");

module.exports = function(context) {
      
      function copyFolderSync(sourcePath, destinationPath) {
        if (!fs.existsSync(destinationPath)) fs.mkdirSync(destinationPath)
      
        fs.readdirSync(sourcePath).forEach(dirent => {
          const [srcPath, destPath] = [sourcePath, destinationPath].map(dirPath => path.join(dirPath, dirent))
          const stat = fs.lstatSync(srcPath)
      
          switch (true) {
            case stat.isFile():
                console.log(srcPath)
                console.log(destPath)
              fs.copyFileSync(srcPath, destPath); break
            case stat.isDirectory():
              copyFolderSync(srcPath, destPath); break
            case stat.isSymbolicLink():
              fs.symlinkSync(fs.readlinkSync(srcPath), destPath); break
          }
        })
      }

    console.log("Copying Assets into plugin");
    var folderToCopy = path.join(context.opts.projectRoot,"www","assets");
    var destFolderPath = path.join(context.opts.projectRoot,"plugins",context.opts.plugin.id,"assets");

    if(fs.existsSync(folderToCopy)){
        copyFolderSync(folderToCopy,destFolderPath);
    }
    console.log("Finished Copying Assets into plugin");
}