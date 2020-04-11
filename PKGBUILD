pkgname=tabbed
gitname=tabbed
pkgver=0.6
pkgrel=1
pkgdesc='Tabs for X11'
arch=('x86_64')
source=('git+https://github.com/SearyBlue/tabbed')
depends=('xorg-xprop' 'xorg-xwininfo')
sha1sums=('SKIP')
provides=('tabbed')
conflicts=('tabbed' 'tabbed-git')
build() 
{
	cd "$srcdir/$gitname"
	make
}

package() 
{
  	cd "$srcdir/$gitname"
  	make PREFIX=/usr DESTDIR="${pkgdir}" install
}
