
#importing modules
import subprocess
import optparse
import re

#function for handling user input(arguments)
def getting_arguments():
    parser = optparse.OptionParser()
    parser.add_option("-i", "--interface", dest="interface", help="enter the interface")
    parser.add_option("-m", "--mac", dest="new_mac", help="enter new mac")
    (options, arguments) = parser.parse_args()
    if not options.interface:
        parser.error("[-] Interface not specified, use --help for more information.")
    elif not options.new_mac:
        parser.error("[-] Mac address not specified, use --help for more information.")
    return options


#function for changing MAC address
def changing_mac(interface, new_mac):
    print("[+] Changing MAC address for " + interface + " to " + new_mac)
    subprocess.call(["ifconfig", interface, "down"])
    subprocess.call(["ifconfig", interface, "hw", "ether", new_mac])
    subprocess.call(["ifconfig", interface, "up"])


#function for getting search results
def get_current_mac(interface):
    ifconfig_result = subprocess.check_output(["ifconfig", options.interface])

    mac_address_search_result = re.search(r"\w\w:\w\w:\w\w:\w\w:\w\w:\w\w", ifconfig_result)
    if mac_address_search_result:
        return mac_address_search_result.group(0)
    else:
        print("[-] Could not read Mac Address.")


options = getting_arguments()
current_mac = get_current_mac(options.interface)
print("Current MAC = " + str(current_mac))

changing_mac(options.interface, options.new_mac)

#verifying whether MAC has changed or not
current_mac = get_current_mac(options.interface)
if current_mac == options.new_mac:
    print("[+] MAC Address was successfully changed to " + current_mac)
else:
    print("[-] MAC address did not get changed.")
