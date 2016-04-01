const spawn = require('child_process').spawn
const path = require('path')
const babelnode = spawn(
        path.join('babel-node')
      , [
        '--presets'
        , 'es2015'
        , path.join(__dirname, 'generate-tokentype-structs.es6')
        ]
      , {
        cwd: path.join(__dirname, '..', 'node_modules', '.bin')
      })


babelnode.stdout.pipe(process.stdout)
babelnode.stderr.pipe(process.stderr)
babelnode.on('close', code => process.exit(code))
