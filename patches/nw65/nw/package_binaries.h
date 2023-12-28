                           'lib/libEGL.so',
                           'lib/libGLESv2.so',
                           'lib/libvulkan.so.1',
                           'lib/libvk_swiftshader.so',
                           'lib/vk_swiftshader_icd.json'
                           ]
        if flavor == 'sdk':
            target['input'].append('nwjc')
            target['input'].append('payload')
            target['input'].append('chromedriver')
            target['input'].append('minidump_stackwalk')
        if flavor in ['nacl','sdk'] :
            target['input'] += ['nacl_helper', 'nacl_helper_bootstrap', 'pnacl']
            if arch == 'x64':
                target['input'].append('nacl_irt_x86_64.nexe')
            elif arch == 'ia32':
                target['input'].append('nacl_irt_x86_32.nexe')
            else:
                target['input'].append('nacl_irt_{}.nexe'.format(arch))
            
    elif platform_name == 'win':
        target['input'] = [
//----replace
                           'lib/libEGL.so',
                           'lib/libGLESv2.so',
                           'lib/libvulkan.so.1',
                           ]
        if flavor == 'sdk':
            target['input'].append('nwjc')
            target['input'].append('payload')
            target['input'].append('chromedriver')
            target['input'].append('minidump_stackwalk')
            
    elif platform_name == 'win':
        target['input'] = [