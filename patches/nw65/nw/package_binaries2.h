            os.mkdir(folder)
            if platform_name == 'linux':
                os.mkdir(os.path.join(folder, 'lib'))
            if platform_name in ['linux', 'win']:
                os.mkdir(os.path.join(folder, 'swiftshader'))
            for f in t['input']:
                src = os.path.join(binaries_location, f)
                dest = os.path.join(folder, f)
//----replace
            os.mkdir(folder)
            if platform_name == 'linux':
                os.mkdir(os.path.join(folder, 'lib'))
            for f in t['input']:
                src = os.path.join(binaries_location, f)
                dest = os.path.join(folder, f)