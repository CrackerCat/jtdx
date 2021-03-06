subroutine ft8_downsample(newdat,f0,nqso,c1,c2,c3,lhighsens)

! Downconvert to complex data sampled at 200 Hz ==> 32 samples/symbol
  use ft8_mod1, only : dd8,windowc1,facc1
  parameter (NFFT1=192000,NFFT2=3200)      !192000/60 = 3200
  
  logical newdat
  complex, intent(out) :: c1(0:3199),c2(0:3199),c3(0:3199)
  complex cx(0:96000),cxx(0:96000) ! 0:NFFT1/2
  real x(NFFT1)
  real, intent(in) :: f0
  integer, intent(in) :: nqso
  logical(1), intent(in) :: lhighsens
  equivalence (x,cx)
  save cxx

  if(newdat) then
! Data in dd have changed, recompute the long FFT
     x(1:180000)=dd8
     x(180001:NFFT1)=0.                       !Zero-pad the x array
     call four2a(cx,NFFT1,1,-1,0)             !r2c FFT to freq domain
     newdat=.false.
     cxx=cx
  endif

  df=0.0625 ! 12000.0/NFFT1
!  tonewidth=6.25 Hz ! 12000.0/1920.
  i0=nint(f0/df)
  ft=f0+55.75; it=min(nint(ft/df),96000)
  fb=f0-5.75; ib=max(1,nint(fb/df))
  c1=cmplx(0.0,0.0)
  k=it-ib
  c1(0:k)=cxx(ib:it)
  c1(0:54)=c1(0:54)*windowc1(54:0:-1)
  c1(k-54:k)=c1(k-54:k)*windowc1
  c1=cshift(c1,i0-ib)
  if(lhighsens) then; c1(0)=c1(0)*1.93; c1(799)=c1(799)*1.7; c1(800)=c1(800)*1.7; c1(3199)=c1(3199)*1.93; endif
  call four2a(c1,NFFT2,1,1,1)            !c2c FFT back to time domain
  c1=facc1*c1
  if(nqso.gt.1) then; do i=0,3198; c2(i)=c1(i)+c1(i+1); enddo; c2(3199)=c1(3199); c2=c2/2; endif
  if(nqso.eq.3) then; do i=1,3199; c3(i)=c1(i-1)+c1(i); enddo; c3(0)=c1(0); c3=c3/2; endif

  return
end subroutine ft8_downsample
