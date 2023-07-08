# Stroopwafel plugin to destroy MLC format

This plugin for [stroopwafel](https://github.com/shinyquagsire23/stroopwafel) packages IOSU patches from [GaryOrderNichts](https://github.com/GaryOderNichts) and quarky for easy usage.

- Forces the MLC size to 5GB (Patch by Gary)

- Format MLC if it gets detected raw

If the size of the MLC changes, it will be detected as raw. My setting the MLC to this unusual size and enabling the "Format if needed" in IOSU the mlc will be formatted and a existing wfs will be destoryed.
If the Installer is then wafel_setup_mlc is then booted without this patch it will format again to the right capacity.

This Plugin can not be used together with the wafel_unlimit_mlc plugin.

**Warning** SLCCMPT will also be formatted if it is detected RAW for some reason.

## Building

```bash
export STROOPWAFEL_ROOT=/path/too/stroopwafel-repo
make
```

## Thanks

- GaryOderNichts for the IOSU patches
- Quarky Format patch
- shinyquagsire23 for defuse, minute and stroopwafel
