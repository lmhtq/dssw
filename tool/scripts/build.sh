make bzImage -j4
make modules
make modules_install
cp -v arch/x86_64/boot/bzImage /boot/vmlinuz-linux-3.15-5
mkinitcpio -k 3.15-5-ARCH -g /boot/initramfs-linux-3.15-5.img
grub-mkconfig -o /boot/grub/grub.cfg
