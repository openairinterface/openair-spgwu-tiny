#!/usr/bin/env python3
# SPDX-License-Identifier: MIT

from jinja2 import Environment, FileSystemLoader
import socket
import os
import sys

CONFIG_FILE = str(os.getenv('CONFIG_FILE','/openair-spgwu-tiny/etc/spgw_u.conf'))
MOUNT_CONFIG = str(os.getenv('MOUNT_CONFIG','no')).lower()

def resolve(hostname):
    try:
        return socket.gethostbyname(hostname)
    except socket.error:
        print(f"Not able to resolve {hostname}")

def render(filepath,funcs,values):
    env = Environment(loader=FileSystemLoader(os.path.dirname(filepath)))
    jinja_template = env.get_template(os.path.basename(filepath))
    jinja_template.globals.update(funcs)
    template_string = jinja_template.render(env=values)
    return template_string

env_variables = dict()
#list of all the environment variables
for name, value in os.environ.items():
    env_variables.update({name:value})

if MOUNT_CONFIG != "yes":
    output = render(CONFIG_FILE,{"resolve":resolve},env_variables)
    with open(CONFIG_FILE, "w") as fh:
        fh.write(output)
    print(f"Configuration file {CONFIG_FILE} is ready")
else:
    print("Configuration file is mounted to the network function")
if len(sys.argv) == 1:
    sys.exit(0)
os.execvp(sys.argv[1], sys.argv[1:])     #important for running the network function it works like exec $@
